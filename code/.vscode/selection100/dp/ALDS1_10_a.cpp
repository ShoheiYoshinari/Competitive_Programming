#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main(){
    int n;
    cin >> n;
    int dp[45];

    dp[0] = 1;
    dp[1] = 1;
    rep2(i, 2, n) dp[i] = dp[i-1] + dp[i-2];
    cout << dp[n] << endl;
    return 0;
}
