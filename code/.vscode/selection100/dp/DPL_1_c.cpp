#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()

ll N ,W;
ll v[109], w[109];
ll dp[109][10009];

int main(){
    cin >> N >> W;
    rep(i, N) cin >> v[i] >> w[i];

    rep(i, N){
        rep(j, W+1){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j - w[i] >= 0){
                dp[i+1][j] = max(dp[i+1][j], dp[i+1][j-w[i]] + v[i]);
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;

}