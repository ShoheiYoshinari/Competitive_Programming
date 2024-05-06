#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    //１からｎまで全探索して、ｎの税抜き価格と同じ値になるiの値を出力。
    int n;
    cin >> n;
    rep(i, n){
        int cnt = (int)(i * 1.08);
        if(cnt == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}