#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int w, h, n, p, q;
    cin >> w >> h >> n;
    vector<vector<int>> x(n, vector<int>(n, 0));
    rep(i, n){
        cin >> p >> q;
        x[p][q] = 1;
    }
    int a1, b1;
    cin >> a1;
    vector<int> a(a1);
    rep(i, a1) cin >> a[i];
    cin >> b1;
    vector<int> b(b1);
    rep(i, b1) cin >> b[i];

    vector<vector<int>> s(a+1, vector<int>(b+1, 0));
    rep(i, a1){
        rep2(j, 1, b1){
            s[i][j] = s[i][j-1] + x[i][j];
        }
    }
    rep(i, b1){
        rep2(j, 1, a1){
            s[i][j] = s[i-1][j] + x[i][j];
        }
    }
    int mi = 1000009, ma = -1;
    rep(i, n-1){
        int num = s[a[i+1]][b[i+1]] + s[a[i]-1][b[i]-1] - s[a[i]-1][b[i+1]] - s[a[i+1]][b[i]-1];
        mi = min(mi, num);
        ma = max(ma, num);
    }
    cout << mi << ' ' << ma << endl;



    


}