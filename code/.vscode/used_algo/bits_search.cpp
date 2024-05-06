#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int n, k, a[29];

int main(){
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    bool ans = false;
    rep(i, 1<<n){
        int sum = 0;
        rep2(j, 1, n){
            int wari = (1 << (j-1));
            if((i/wari)%2 == 1) sum += a[j];
        }
        if(sum == k) ans = true;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}