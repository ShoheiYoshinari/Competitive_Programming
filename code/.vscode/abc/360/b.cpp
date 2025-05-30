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

int main() {
    string s, t;
    cin >> s >> t;
    for(int cnt = 1; cnt < (int)s.size(); cnt++){
        string res = "";
        for(int i = cnt-1; i >= 0; i--){
            rep(j, s.size()){
                if(j%cnt == i) res += s[j];
            }
            if(res == t){
                cout << "Yes" << endl;
                return 0;
            }
            res = "";
        }
    }
    //cout << cnt << endl;
    cout << "No" << endl;
    return 0;
}