#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    int f = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] != f+i){
            cout << a[i]-1 << endl;
            return 0;
        }
    }
    cout << endl;
}