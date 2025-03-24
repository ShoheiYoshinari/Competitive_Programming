#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

struct BipartiteMatching {
    vector< vector< int > > graph;
    vector< int > match, alive, used;
    int timestamp;
  
    BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}
  
    void add_edge(int u, int v) {
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
  
    bool dfs(int idx) {
      used[idx] = timestamp;
      for(auto &to : graph[idx]) {
        int to_match = match[to];
        if(alive[to] == 0) continue;
        if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
          match[idx] = to;
          match[to] = idx;
          return true;
        }
      }
      return false;
    }
  
    int bipartite_matching() {
      int ret = 0;
      for(int i = 0; i < graph.size(); i++) {
        if(alive[i] == 0) continue;
        if(match[i] == -1) {
          ++timestamp;
          ret += dfs(i);
        }
      }
      return ret;
    }
  
    void output() {
      for(int i = 0; i < graph.size(); i++) {
        if(i < match[i]) {
          cout << i << "-" << match[i] << endl;
        }
      }
    }
  };
  

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, vector<int>> mp;
    rep(i, n) mp[a[i]].push_back(i);
    while(q--){
        int x, y;
        cin >> x >> y;
        x--;
        mp[a[x]].erase(remove(all(mp[a[x]]), x), mp[a[x]].end());
        a[x] = y;
        mp[y].push_back(x);

        BipartiteMatching bm(n);
        for(auto [k, v] : mp){
            for(int i = 0; i < v.size(); i++){
                for(auto p2 : mp[(k+1)%m]){
                    if(v[i] < p2){
                        bm.add_edge(v[i], p2);
                    }
                }
            }
        }
        cout << bm.bipartite_matching() << endl;
    }
    return 0;
}