#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int cnt[26] = {0};
    rep(i, s.length()) cnt[s[i] - 'a']++;
    rep(i, 26){
        if(cnt[i] == 0){
            cout << char('a' + i) << endl; // char型でなければ数字が出力される
            return 0;
        }
    }
    cout << "None" << endl;
}