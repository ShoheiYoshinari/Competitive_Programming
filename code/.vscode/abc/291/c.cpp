#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    string s;
    cin >> n >> s;
    int x = 0;
    int y = 0;
    set<pair<int,int>>used({{0,0}});

    rep(i, n) {
        if(s[i] == 'R') x++;
        if(s[i] == 'L') x--;
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;
        if(used.find({x,y}) != used.end()){
            cout << "Yes" << endl;
            return 0;
        }
        uesd.insert({x,y});
    }
     cout << "No" << endl;
}