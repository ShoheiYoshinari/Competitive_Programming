#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main(){
    int m, n;
    cin >> m;
    vector<long long> px(m), py(m);
    rep(i, m) cin >> px[i] >> py[i];
    cin >> n;
    vector<long long> sx(n), sy(n);
    rep(i, n) cin >> sx[i] >> sy[i];

    rep(i, n){
        long long dx = sx[i] - px[0];
        long long dy = sy[i] - py[0];
        bool ok = true;
        rep(j, m){
            if(find(sx.begin(), sx.end(), px[j]+dx) != sx.end() && find(sy.begin(), sy.end(), py[j]+dy) != sy.end()){
                continue;
            }else{
                ok = false;
            }
        }
        if(ok){
            cout << dx << ' ' << dy << endl;
            return 0;
        }
    }
}