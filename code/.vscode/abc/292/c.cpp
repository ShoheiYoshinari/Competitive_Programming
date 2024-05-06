#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    
    long long ans = 0;

    // X+Y=NとなるようなX,Yを求める。Xが決まるとYも決まる。o(N)
    for (int i = 1; i < n; i++) {
        long long x = i, y = n-i;
        long long x_num = 0, y_num = 0;
        //　AB=x，CD=yとおくと、Aが決まるとBも決まる。CDも同様。O(logN)
        //　Xを素因数分解して、AB=NとなるようなA,Bの通り数を求める。
        for (int j = 1; j*j <= i; j++) {
            // x/j = aとなれば、x=j*aが成り立つ。
            if(x % j == 0) {
                x_num++;
                // AとBが同じ値の時、一通りになる。
                if(x != j*j) x_num++;
            }
        }
        //　yも同様。
        for (int j = 1; j*j <= n-i; j++) {
            if(y % j == 0) {
                y_num++;
                if(y != j*j) y_num++;
            }
        }
        ans += x_num * y_num; 
    }
    cout << ans << endl;
}
