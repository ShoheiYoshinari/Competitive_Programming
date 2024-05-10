#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};
const double PI = acos(-1);

const int di6_odd[] = {-1, 0, 0, 1, 1, 1};
const int dj6_odd[] = {0, -1,  1, -1, 0, 1};
const int di6_even[] = {-1, -1, -1, 0, 1, 0};
const int dj6_even[] = {0, -1, 1, -1, 0, 1};

int main(){
    int h, w;
    cin >> h >> w;
    
    char s[w+1][h+1];
    rep2(i, 1, w){
        rep2(j, 1, h) cin >> s[i+1][j+1];
    }

    bool visited[w+1][h+1];
    queue<pair<int, int> > q;


    int cnt = 0;
    rep2(i, 1, w){
        rep2(j, 1, h){
            if(i != 1 && i != w && j != 1 && j != h) continue;
            if(s[i][j] == '1'){
                if(j%2 == 1){
                    rep(v, 6){
                        int ni = i + di6_even[v];
                        int nj = j + dj6_even[v];
                        if(ni <= 0 || ni > w || nj <= 0 || nj > h) cnt++;
                    }
                }else{
                    rep(v, 6){
                        int ni = i + di6_odd[v];
                        int nj = j + dj6_odd[v];
                        if(ni <= 0 || ni > w || nj <= 0 || nj > h) cnt++;
                    }
                }
            }else if(s[i][j] == '0'){
                if(visited[i][j] == true) continue;
                visited[i][j] = true;
                q.emplace(i, j);
                if(j%2 == 1){
                    while(!q.empty()){
                        auto [ii, jj] = q.front(); q.pop();
                        visited[ii][jj] = true; 
                        rep(v, 6){
                        int ni = ii + di6_even[v];
                        int nj = jj + dj6_even[v];
                        if(ni <= 0 || ni > w || nj <= 0 || nj > h) continue;
                        if(visited[ni][nj] == true) continue;
                        if(s[ni][nj] == '0') q.emplace(ni, nj);
                        if(s[ni][nj] == '1') cnt++;
                        }
                    }
                }else{
                    while(!q.empty()){
                        auto [ii, jj] = q.front(); q.pop();
                        visited[ii][jj] = true; 
                        rep(v, 6){
                        int ni = ii + di6_odd[v];
                        int nj = jj + dj6_odd[v];
                        if(ni <= 0 || ni > w || nj <= 0 || nj > h) continue;
                        if(visited[ni][nj] == true) continue;
                        if(s[ni][nj] == '0') q.emplace(ni, nj);
                        if(s[ni][nj] == '1') cnt++;
                        }
                    }
                }
            }
            cout << i << " " << j << endl;
            cout << cnt << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}