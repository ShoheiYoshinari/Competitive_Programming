#include <bits/stdc++.h>
using namespace std;

int main () {
    // 入力
    int n, m;
    cin >> n >> m;
    
    // つながっているかを管理する変数
    vector<bool> v(n + 1, false);
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v[a] = true;  // つながっている
    }
  
    // 1 から n まで繰り返し
    int left = 1;
    while(left <= n) {
        // 連結成分の一番大きい値
        int right = left;
        // つながっている場合は右にずらす
        while(v[right]) right++;

        // 右の値から左の値まで順に出力
        for(int j = right; j >= left; j--) {
            cout << j << ' ';
        }
      
        // 次の連結成分に移動
        left = right + 1;
    }

    return 0;
}