#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
const double PI = acos(-1);

int h, w, n;
int ee[209][209];
char a[209][209];
bool ok[209][209];
int sx, sy, gx, gy;
bool ans = false;

void dfs(int posx, int posy, int e, int ee[209][209]){

    if(e < ee[posx][posy]){
        e = ee[posx][posy];
        ee[posx][posy] = 0;
    }

    if(a[posx][posy] == 'T') ans = true;
    if(e <= 0) return ;

    rep(i, 4){
        int nextx = posx + dx[i];
        int nexty = posy + dy[i];

        if(nextx < 1 || w < nextx || nexty < 1 || h < nexty) continue;
        if(a[nextx][nexty] == '#') continue;

        dfs(nextx, nexty, e-1, ee);
    }
    return ;
}



int main(){
    cin >> h >> w;
    rep2(i, 1, h){
        rep2(j, 1 ,w){
            cin >> a[i][j];
            if(a[i][j] == 'S') sx = i, sy = j;
            if(a[i][j] == 'T') gx = i, gy = j;
        }
    }
    cin >> n;
    int r, c, e;
    rep(i, n){
        cin >> r >> c >> e;
        ee[r][c] = e;
    }

    int energy = 0;
    dfs(sx, sy, energy, ee);
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}