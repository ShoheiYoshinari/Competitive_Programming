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

int n;
int a, b;

int main(){
    cin >> n;
    vector<pair<int, int> > v;
    map<int, int> cnta, cntb;
    rep(i, n){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        cnta[a]++;
        cntb[b]++;
    }

    int osu = 0;
    int ou = 0;
    int uo = 0;

    rep(i, n){
        rep2(j, i+1, n){
            if(v[i].first == v[j].first || v[i].second == v[j].second){
                cout << v[i].first << " " << v[j].first << endl;
                if(v[i].first == v[j].first && v[i].second == v[j].second){
                    osu++;
                    continue;
                }

                if(cnta[v[i].first] >= 2){
                    if(cntb[v[i].second]%2 == 0) ou++;
                }
                if(cntb[v[i].second] >= 2){
                    if(cnta[v[i].first]%2 == 0) uo++;
                }
            }
        }
    }
    cout << osu << uo << ou << endl;

    if((n-osu*2-uo/2-ou/2)%2) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
    return 0;
    
}