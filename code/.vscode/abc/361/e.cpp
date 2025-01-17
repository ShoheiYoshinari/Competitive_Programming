#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

using Graph = vector<vector<pair<ll, ll>>>;
ll n;
ll ans = 0;
vector<ll> dist(1e5*2, -1), dist2(1e5*2, -1);

void BFS(Graph &G, vector<ll> &dist, ll f){
    queue<ll> que;
    que.push(f);
    dist[f] = 0;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(auto [nvf, nvs] : G[v]){
            if(dist[nvf] != -1) continue;
            dist[nvf] = dist[v] + nvs;
            que.push(nvf);
        }
    }
    return ;
}

//各辺の二倍の長さをansで保持
//ansから連結した辺の最長距離を引く
int main() {
    cin >> n;
    Graph G(n);
    rep(i, n-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        ans += c*2;
    }
    //cout << ans << endl;

    ll dist_max = 0;
    ll pos = -1;
    BFS(G, dist, 0);
    rep(i, n){
        if(dist_max < dist[i]){
            dist_max = dist[i];
            pos = i;
        }
    }
    //cout << pos << endl;

    ll dist_max2 = 0;
    ll pos2 = -1;
    BFS(G, dist2, pos);
    rep(i, n){
        //cout << dist2[i] << ' ';
        chmax(dist_max2, dist2[i]);
    }

    cout << ans - dist_max2 << endl;
    return 0;
}