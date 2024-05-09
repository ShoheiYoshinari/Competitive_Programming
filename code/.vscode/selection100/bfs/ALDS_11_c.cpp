#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, u, k, v;
int main(){
    cin >> n;

    Graph G(n);
    rep(i, n){
        cin >> u >> k;
        u--;
        rep(j, k){
            cin >> v;
            v--;
            G[u].push_back(v);
        }
    }

    queue<int> que;
    vector<int> dist(n, -1);

    dist[0] = 0;
    que.push(0);

    while(!que.empty()){
        int v = que.front(); que.pop();

        for(int nv : G[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    rep(i, n) cout << i+1 << ' ' << dist[i] << endl;
    return 0;
}