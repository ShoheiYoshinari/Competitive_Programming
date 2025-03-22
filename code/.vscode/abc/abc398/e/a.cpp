#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1,_2,_3,name,...) name
#define rep1(i,n) for(auto i = std::decay_t<decltype(n)>{}; i != (n); ++i)
#define rep2(i,l,r) for(auto i = (l); i != (r); ++i)
#define rep(...) OVERLOAD_REP(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define exists(s,x) ((s).find(x) != (s).end())
template<class T> bool chmin(T &a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> bool chmax(T &a, T b){ if(a < b){ a = b; return true; } return false; }
template<class T> constexpr T inf(){ return ::std::numeric_limits<T>::max(); }
template<class T> constexpr T hinf(){ return inf<T>() / 2; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
struct init {
    init() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout << fixed << setprecision(20);
    }
} init;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, 1, n){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c(n, -1);
    function<void(int, int)> dfs = [&](int u, int col){
        c[u] = col;
        for(auto v : g[u]){
            if(c[v] == -1) dfs(v, col^1);
        }
    };
    dfs(1, 0);

    vector<int> a, b;
    rep(i, n){
        if(c[i] == 0) a.push_back(i);
        else b.push_back(i);
    }
    set<pair<int, int>> st;
    rep(u, n){
        for(auto v : g[u]){
            if(u < v) st.insert({u, v});
        } 
    }
    vector<pair<int, int>> ed;
    for(auto x : a){
        for(auto y : b){
            int i = min(x, y);
            int j = max(x, y);
            if(!exists(st, {i, j})) ed.push_back({i, j});
        }
    }
    sort(all(ed));
    int m = ed.size();
    vector<int> pr(m, -1);
    map<pair<int, int>, int> mp;
    rep(i, 0, m / 2){
        int idx = 2 * i;
        pr[idx] = idx + 1;
        pr[idx + 1] = idx;
        mp[ed[idx]] = idx;
        mp[ed[idx + 1]] = idx + 1;
    }
    int ex = -1;
    if(m % 2 == 1){
        ex = m - 1;
        mp[ed[ex]] = ex;
    }
    bool fst = (m % 2 == 1);
    cout << (fst ? "First" : "Second") << endl;
    fflush(stdout);
    vector<bool> used(m, false);
    auto play = [&](int idx){
        used[idx] = true;
        cout << ed[idx].first << " " << ed[idx].second << endl;
        fflush(stdout);
    };
    if(fst){
        if(ex != -1) play(ex);
        else if(m > 0) play(0);
    }
    while(true){
        int u, v;
        cin >> u >> v;
        if(u == -1 && v == -1)
            break;
        pair<int, int> op = {u, v};
        int idx = -1;
        if(mp.count(op))
            idx = mp[op];
        if(idx != -1 && pr[idx] != -1 && !used[pr[idx]]){
            play(pr[idx]);
        }else{
            bool done = false;
            rep(i, 0, m){
                if(!used[i]){
                    play(i);
                    done = true;
                    break;
                }
            }
            if(!done) break;
        }
    }
    return 0;
}
