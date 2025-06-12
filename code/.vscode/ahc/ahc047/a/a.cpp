#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()

typedef struct Node {
    int next[6];
    int link;
    vector<int> out;
    Node() {
        fill(begin(next), end(next), -1);
        link = -1;
    }
} Node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll L;
    cin >> N >> M >> L;
    vector<string> patterns(N);
    vector<int> P(N);
    rep(i, N) cin >> patterns[i] >> P[i];

    // Build Aho–Corasick
    vector<Node> aho;
    aho.emplace_back();
    auto idx = [&](char c){ return c - 'a'; };
    rep(i, N) {
        int v = 0;
        for (char ch : patterns[i]) {
            int c = idx(ch);
            if (aho[v].next[c] == -1) {
                aho[v].next[c] = aho.size();
                aho.emplace_back();
            }
            v = aho[v].next[c];
        }
        aho[v].out.push_back(i);
    }
    // Failure links
    queue<int> q;
    rep(c, 6) {
        if (aho[0].next[c] != -1) {
            aho[aho[0].next[c]].link = 0;
            q.push(aho[0].next[c]);
        } else {
            aho[0].next[c] = 0;
        }
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        rep(c, 6) {
            int u = aho[v].next[c];
            if (u != -1) {
                aho[u].link = aho[aho[v].link].next[c];
                // merge outputs
                for (int x : aho[aho[u].link].out)
                    aho[u].out.push_back(x);
                q.push(u);
            } else {
                aho[v].next[c] = aho[aho[v].link].next[c];
            }
        }
    }
    int S = aho.size();

    // Score per trie node
    vector<ll> score(S, 0);
    rep(v, S) for (int idx_p : aho[v].out) score[v] += P[idx_p];

    // Select top M nodes
    vector<int> order(S);
    iota(all(order), 0);
    sort(all(order), [&](int a, int b){ return score[a] > score[b]; });
    vector<int> node2state(S, 0);
    rep(i, M) node2state[order[i]] = i;

    // Build transition matrix A
    vector<vector<int>> A(M, vector<int>(M, 0));
    rep(v, S) {
        int st = node2state[v];
        vector<ll> w(M, 0);
        rep(c, 6) {
            int u = aho[v].next[c];
            int ns = node2state[u];
            w[ns]++;
        }
        ll sumw = accumulate(all(w), 0LL);
        if (sumw == 0) continue;
        int base = 0;
        rep(j, M) {
            A[st][j] = w[j] * 100 / sumw;
            base += A[st][j];
        }
        int rem = 100 - base;
        vector<pair<ll,int>> ord;
        rep(j, M) ord.emplace_back(w[j], j);
        sort(ord.rbegin(), ord.rend());
        rep(k, rem) A[st][ord[k].second]++;
    }
    // Normalize rows
    rep(i, M) {
        int sum = accumulate(all(A[i]), 0);
        int rem = 100 - sum;
        rep(j, rem) A[i][j % M]++;
    }

    // Assign output char for each state: pick most frequent transition
    vector<char> C(M, 'a');
    rep(i, M) {
        // find char with max sum of outgoing weight
        vector<ll> cnt(6, 0);
        rep(j, M) cnt[j % 6] += A[i][j];
        int best = max_element(all(cnt)) - cnt.begin();
        C[i] = char('a' + best);
    }

    // Output
    rep(i, M) {
        cout << C[i];
        rep(j, M) cout << ' ' << A[i][j];
        cout << '\n';
    }
    return 0;
}
