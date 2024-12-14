#include <bits/stdc++.h>
using namespace std;
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
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

using Graph = vector<vector<ll>>;
Graph G;
ll h, w, x;
ll ans = 0;
void dfs(vector<vector<bool>> &seen, ll sy, ll sx, ll health) {
    seen[sy][sx] = true;
    cout << sy << ' ' << sx << endl;
    rep(dir, 4){
        ll ny = sy + dy[dir];
        ll nx = sx + dx[dir];
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if(seen[ny][nx] == true) continue;
        if(health <= G[ny][nx]*x) continue;
        dfs(seen, ny, nx, chmax(ans, health)+G[ny][nx]);
    }
}

int main(){
    cin >> h >> w >> x;
    ll sy, sx;
    cin >> sy >> sx;
    sy--, sx--;

    G.resize(h);
    rep(i, h){
        G[i].resize(w);
        rep(j, w) cin >> G[i][j];
    }
    vector<vector<bool>> seen(h, vector<bool> (w, false));
    ll health = G[sy][sx];
    dfs(seen, sy, sx, health);

    cout << ans << endl;
    return 0;
}