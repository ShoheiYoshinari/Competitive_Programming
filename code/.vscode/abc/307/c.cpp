#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int ha, wa;
    cin >> ha >> wa;
    vector<string> a(ha);
    rep(i, ha) cin >> a[i];
    int hb, wb;
    cin >> hb >> wb;
    vector<string> b(hb);
    rep(i, hb) cin >> b[i];
    int hx, wx;
    cin >> hx >> wx;
    vector<string> x(hx);
    rep(i, hx) cin >> x[i];

    char in[10][10] = {'.'};
    rep(a, ha){
        rep(b, wa){
            rep(c, hb){
                rep(d, wb){
                    rep(i, 10){
                        rep(j, 10){
                            if(a[i+a][j+b] == '#' && i+a < ha && j+b < wa) in[i][j] == '#';
                            if(b[i+c][j+d] == '#' && i+c < hb && j+d < wb) in[i][j] == '#';

                            bool ans = true;

                            rep(k, hx){
                                rep(l, wx){
                                    if(x[i][j] != in[i][j]){
                                        ans = false;
                                        break;
                                    }
                                }
                            }
                            if(ans) {
                                cout << "Yes" << endl;
                                return 0;
                            }

                        }
                    }
                }
            }
        }
    }





}