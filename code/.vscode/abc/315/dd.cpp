#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int h, w, n;
char a[209][209];
int e[209][209];

int main(){
    cin >> h >> w;
    rep2(i, 1, h){
        rep2(j, 1, w) cin >> a[i][j];
    }
    cin >> n;
    int r, c, ee;
    rep(i, n){
        cin >> r >> c >> ee;
        e[r][c] = ee;
    }

    
}