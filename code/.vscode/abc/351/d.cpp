#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

using ll = long long;

int h, w;
vector<string> s(h);

vector visited(h, vector<bool>(w));
vector last(h, vector<int>(w));


int bfs(int x, int y, int tm){
    int sum = 0;
    visited[x][y] = true;
    sum++;
    rep(i, 4){
        int nextx = x + di[i];
        int nexty = y + dj[i];
        if(nextx < 0 || nextx >= h || nexty < 0 || nexty >= w) continue;
        if(s[nextx][nexty] == '#') continue;
        if(visited[nextx][nexty] == true) continue;  
        if(s[nextx][nexty] == '$'){
            if(last[nextx][nexty] != tm){
                last[nextx][nexty] = tm;
                sum++;
                continue;
            }
        }
        sum += bfs(nextx, nexty, tm);
    }
    return sum;
    
}

int main(){
    cin >> h >> w;
    vector<pair<int, int> > zis;
    rep(i, h){
        cin >> s[i];
        rep(j, w){
            if(s[i][j] == '#') zis.push_back(make_pair(i, j));
        }
    }

    for(auto [x, y] : zis){
        rep(i, 4){
            int nextx = x + di[i];
            int nexty = y + dj[i];
            if(nextx < 0 || nextx >= h || nexty < 0 || nexty >= w) continue;
            if(s[nextx][nexty] == '#') continue;
            s[nextx][nexty] = '$';
        }
    }

    rep(i, h){
        rep(j, w) cout << s[i][j];
        cout << endl;
    }

    int ans = 1, tm = 1, tmp;
    rep(i, w){
        rep(j, h){
            if(s[i][j] == '#' || s[i][j] == '$') continue;
            if(!visited[i][j]) continue;
            tmp = bfs(i, j, tm);
            ans = max(ans, tmp);
            tm++;
        }
    }
    cout << ans << endl;
    return 0;
    


    
}