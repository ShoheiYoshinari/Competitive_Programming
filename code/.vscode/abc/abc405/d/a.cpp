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
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

using Graph = vector<vector<int>>;
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}


using Graph = vector<vector<int>>;
int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<vector<int>> dist(h, vector<int>(w, 0));
    vector<pair<int, int>> p;
    rep(i, h){
        rep(j, w){
            if(s[i][j] == "#") dist[i][j] = -1;
            if(s[i][j] == "E"){
                dist[i][j] = -2;
                p.push_bacK({i, j});
            }
        }
    }

    for(auto v : p){

        queue<pair<int, int>> q;
        q.push(v);
        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();
            rep(dir, 4){
                int ni = i + di[dir];
                int nj = j = dj[dir];

                if(ni < 0 || ni >= h || nj < 0 || nj > w) continue;
                if(dist[ni][nj] == -2 || dist[ni][nj] == -1) continue;
                if(dist[ni][nj] != 0) continue;
                
                if(dist[ni][nj] > dist[i][j]+1){
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }

    



}