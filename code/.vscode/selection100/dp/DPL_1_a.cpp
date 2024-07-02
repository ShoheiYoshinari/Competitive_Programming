#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
//using ull = unsigned long long;
//const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
//#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()
//#define exists(c, e) ((c).find(e) != (c).end()

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m+1, 0);
    rep2(i, 1, m) cin >> c[i];
    vector<vector<int> > dp(m+1, vector<int>(n+1, INT_MAX));

    dp[0][0] = 0;
    rep2(i, 1, m){
        rep2(j, 0, n){
            dp[i][j] = dp[i-1][j];
            if(j >= c[i] && dp[i][j-c[i]] != INT_MAX){
                dp[i][j] = min(dp[i][j], dp[i][j-c[i]] + 1);
            }
        }
    }
    cout << dp[m][n] << endl;
}