#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()

ll N ,W;
ll v[109], w[109];
ll dp[109][100009];

int main(){
    cin >> N >> W;
    rep2(i, 1, N) cin >> v[i] >> w[i];
    rep(i, N) dp[0][i] = 0;

    rep2(i, 1, N){
        rep2(j, 0, W){
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }

    ll ans = 0;
    rep2(i, 0, W) ans = max(ans, dp[N][i]);
    cout << ans << endl;
    return 0;

}