#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
    int n, h, x, p[109];
    cin >> n >> h >> x;
    rep(i, n) cin >> p[i];

    int ans = 1009;
    rep(i, n){
        if(h + p[i] >= x){
            ans = min(ans, p[i]);
        }
    }
    rep(i, n){
        if(ans == p[i]){
            cout << i << endl;
            return 0;
        }
    }

}