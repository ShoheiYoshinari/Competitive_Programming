#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    vector<int> a(109);
    cin >> n;
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int mx = a[0];
    rep(i, n){
        if(mx != a[i]){
            cout << a[i] << endl;
            return 0;
        }
    }

}