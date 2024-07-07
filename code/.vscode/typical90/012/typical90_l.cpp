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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

vector<vector<ll>> mp(2009, vector<ll> (2009, 0));

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;



int main() {
    ll h, w;
    cin >> h >> w;
    ll Q;
    cin >> Q;
    
    rep(i, Q){
        ll q; cin >> q;
        if(q == 1){
            ll r, c; cin >> r >> c;
            r--, c--;
            mp[r][c]++;
        }else if(q == 2){
            ll sx, sy, gx, gy;
            cin >> sx >> sy >> gx >> gy;
            sx--, sy--, gx--, gy--;

            bool flag = false;
            if(sx == gx && sy == gy && mp[sx][sy] == true){
                cout << "Yes" << endl;
                continue;
            }
            if(mp[sx][sy] > 0 && mp[gx][gy] > 0){
                //BFS
                vector<vector<bool>> seen(h, vector<bool>(w, false));
                queue<pair<ll, ll>> que;

                que.push({sx, sy});
                seen[sx][sy] = true;
                while(!que.empty()){
                    auto [vx, vy] = que.front();
                    que.pop();

                    rep(i, 4){
                        ll nx = vx + dx[i];
                        ll ny = vy + dy[i];
                        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if(mp[nx][ny] == 0) continue;
                        if(seen[nx][ny] == true) continue;

                        que.push({nx, ny});
                        seen[nx][ny] = true;
                        if(nx == gx && ny == gy){
                            flag = true;
                            break;
                        }
                    }
                }
            }
            cout << (flag ? "Yes" : "No") << endl;
        }
    }
    return 0;

}