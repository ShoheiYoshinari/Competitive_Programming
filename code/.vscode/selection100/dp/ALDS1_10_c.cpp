#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
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

//最長共通部分列 LCS

int main() {
    int q;
    cin >> q;

    string x, y;
    rep(i, q){
        cin >> x >> y;
        vector<vector<int> > dp(x.size()+1, vector<int>(y.size()+1, 0));
        rep2(i, 0, x.size()){
            rep2(j, 0, y.size()){
                if(i >= 1 && j >= 1 && x[i-1] == y[j-1]){
                    dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1});
                }else if(i >= 1 && j >= 1){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }else if(i >= 1){
                    dp[i][j] = dp[i-1][j];
                }else if(j >= 1){
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        cout << dp[x.size()][y.size()] << endl;
    }
}