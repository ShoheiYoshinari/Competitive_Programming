#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

int main(){
    int n;
    cin >> n;
    int h[n];
    rep(i, n) cin >> h[i];
    int top = h[0];
    int pos = 0;
    rep(i, n){
        if(top < h[i]){
            pos = i;
            top = h[i];
            break;
        }
    }
    if(pos == 0) cout << -1 << endl;
    else cout << pos + 1 << endl;
}