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

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 1e18;

    rep(i, 1<<n){
        if(__builtin_popcount(i) != k-1) continue;
        if(i&1) continue;

        ll h = 0;
        ll res = 0;
        rep(j, n){
            if(i & (1<<j) || j == 0){
                if(h >= a[j]){
                    res += h-a[j]+1;
                    h++;
                }
                chmax(h, a[j]);
            }
        }
        chmin(ans, res);
    }
    cout << ans << endl;
    return 0; 
}