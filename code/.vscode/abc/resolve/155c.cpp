#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;cin>>n;
    map<string,int> s;

    rep(i, n){
        string cur;
        cin >> cur;
        s[cur]++;
    }
    int cnt_p = -1;
    for(auto &p : s) cnt_p = max(cnt_p, p.second);
    
    for(auto &p : s){
        if(cnt_p == p.second) cout << p.first << endl;
    }
    
}