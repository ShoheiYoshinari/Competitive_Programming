#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long n;
    cin >> n;
    vector<long long> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    long long ans = 0;

    rep2(i, 0, n){
        rep2(j, i+1, n){
            rep2(k, j+1, n){
                double tilt1 = (double)(y[i] - y[j]) / (double)(x[i] - x[j]);
                double tilt2 = (double)(y[j] - y[k]) / (double)(x[j] - x[k]);
                double tilt3 = (double)(y[k] - y[i]) / (double)(x[k] - x[i]);
                if(tilt1 == tilt2 || tilt2 == tilt3 || tilt3 == tilt1) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;

}