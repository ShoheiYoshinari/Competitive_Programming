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
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T> constexpr T HINF() { return INF<T>() / 2; }
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

// Trie木：文字 a～f (6種) を扱う
template <int char_size, int base>
struct Trie {
    struct Node {
        vector<int> next;
        vector<int> accept;
        int common;
        Node() : next(char_size, -1), common(0) {}
    };
    vector<Node> nodes;
    Trie() { nodes.emplace_back(); }
    void insert(const string &word, int id) {
        int v = 0;
        for (char ch : word) {
            int c = ch - base;
            if (nodes[v].next[c] == -1) {
                nodes[v].next[c] = nodes.size();
                nodes.emplace_back();
            }
            nodes[v].common++;
            v = nodes[v].next[c];
        }
        nodes[v].common++;
        nodes[v].accept.push_back(id);
    }
    int size() const { return nodes.size(); }
};

struct INIT {
    INIT() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(20);
    }
} INIT;

int main() {
    int n, m;
    ll l;
    cin >> n >> m >> l;
    vector<string> S(n);
    vector<int> P(n);
    rep(i, n) cin >> S[i] >> P[i];

    // a-f の Trie 木構築
    constexpr int CHAR_SIZE = 6, BASE = 'a';
    Trie<CHAR_SIZE, BASE> trie;
    rep(i, n) trie.insert(S[i], i);
    int T = trie.size();

    // ヒューリスティック：スコア×長さ順ソート
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int a, int b) {
        ll sa = (ll)P[a] * (int)S[a].size();
        ll sb = (ll)P[b] * (int)S[b].size();
        return sa != sb ? sa > sb : P[a] > P[b];
    });

    // 長い文字列を専用パス割り当て
    vector<char> C(m, 'a');
    vector<vector<int>> A(m, vector<int>(m, 0));
    int used = 1;
    rep(idx, order.size()) {
        int i = order[idx];
        int len = S[i].size();
        if (used + len > m) break;
        rep(j, len) {
            int st = used + j;
            C[st] = S[i][j];
            if (j + 1 < len) A[st][st+1] = 100;
            else A[st][0] = 100;
        }
        used += len;
    }
    // 残りはルート循環
    rep(st, used, m) {
        C[st] = char('a' + (st % CHAR_SIZE));
        rep(j, m) A[st][j] = 0;
        A[st][0] = 100;
    }
    // ルート遷移：各専用パス先へ均等
    int K = used - 1;
    if (K > 0) {
        rep(i, 1, used) A[0][i] = 100 / K;
        A[0][0] = 100 - (100 / K) * K;
    } else {
        A[0][0] = 100;
    }

    // 出力
    rep(i, m) {
        cout << C[i];
        rep(j, m) cout << ' ' << A[i][j];
        cout << '\n';
    }
    return 0;
}
