#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    

    ll ans = 1e9;
    rep(ia, 10000){
        rep(ib, 10000){
            ll sum = a*ia + b*ib;
            if(n < sum) continue;
            ll ic = (n-sum)/c;
            if((n-sum)%c == 0 && 0 <= ic && ic < 10000){
                chmin(ans, ia + ib + ic);
            }
        }
    }
    cout << ans << endl;
    return 0;
}