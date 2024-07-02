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
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second; 
    sort(all(p));

    int cnt = 0;

    rep2(i, 0, n){
        rep2(j, 0, n){
            if(p[i].first < p[j].first && p[i].second < p[j].second){
                if((find(p.begin(), p.end(), make_pair(p[i].first, p[j].second)) != p.end()) &&
                (find(p.begin(), p.end(), make_pair(p[j].first, p[i].second)) != p.end())){
                cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}