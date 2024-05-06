#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
    int h,w;
    cin >> h >> w;
    int a[11][11];

    rep(i, h){
        rep(j, w){
            cin >> a[j][i];
        }
    }
    // ｈ方向の移動回数に０、ｗ方向の移動回数に１として格納
    int p[20], l = h+w-2, ans = 0;
    for (int i = 1; i <= l; i++) {
        if(i > w-1) p[i] = 1;
        else p[i] = 0;
    }
    /* setの性質である「同じ数字は格納しない」を利用して（１，１）から（ｈ、ｗ）
     の数字を格納し、同じ数字が重複していないかをsetに格納された個数で調べる
    */ 
    do{
        int x = 1, y = 1;
        set<int> s;
        s.insert(a[1][1]);
        for (int i = 1; i <= l; i++) {
            if(p[i]) y++;
            else x++;
            s.insert(a[x][y]);
       }
       if(s.size() == l+1) ans++;
    }while(next_permutation(p+1, p+l+1));
    // next_permutation:順列を生成する
    // o(n!)
    cout << ans << endl;
    return 0;
}


