#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(200009);
    rep(i, m) cin >> a[i];

    map<int, int> mp;
    int top = 0;
    int p = 0;

    rep(i, m){
        mp[a[i]] += 1;
        if(top < mp[a[i]]){
            top = mp[a[i]];
            p = a[i];
            cout << p << endl;
        }else if(top == mp[a[i]]){
            if(a[i] > p){
                cout << p << endl;
            }else{
                top = mp[a[i]];
                p = a[i];
                cout << p << endl;
            }
        }else{
            cout << p << endl;
        }
    }
    cout << endl;
}