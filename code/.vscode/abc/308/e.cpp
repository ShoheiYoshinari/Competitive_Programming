#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n), m, e, x;
    rep(i, n) cin >> a[i];
    string s;
    cin >> s;


    int ans = 0;
    rep(i, n){
        if(s[i] == 'M') m.insert(i);
        else if(s[i] == 'E') e.insert(i);
        else if(s[i] == 'X') x.insert(i);
    }
}