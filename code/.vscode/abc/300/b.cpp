#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int h ,w;
    cin >> h >> w;
    vector<string> a(h), b(h);
    rep(i, h) cin >> a[i];
    rep(i, h) cin >> b[i];

    rep(i, h){
        rep(j, w){
            bool ans = true;
            rep(k, h){
                rep(l, w){
                    if(a[(i+k) % h][(j+l) % w] != b[k][l]) ans = false;
                }
            }
            if(ans) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

}