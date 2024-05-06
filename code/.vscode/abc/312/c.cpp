#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);


    int min = -1;
    rep(i, n){
        int pos1 = lower_bound(a, a+n, a[i]) - a;
        int pos2 = upper_bound(b, b+m, a[i]) - b;

        if(pos1 + 1 >= m - pos2){
            min = a[i];
            break;
        }
    }
    if(min == -1){
        cout << b[m-1] + 1 << endl;
    }else{
        cout << min << endl;
    }

}