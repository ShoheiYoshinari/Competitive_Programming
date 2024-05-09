#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};


using Graph = vector<set<int> >;
vector<bool> seen;
int n, u, k, v;
int t = 0;

vector<pair<int, int> >  a(109);

void dfs(const Graph &G, int v) {
    t++;
    a[v].first = t;
    seen[v] = true; //v を訪問済みにする
    //v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // 移動先が訪問済みならスルー
        dfs(G, next_v); // 再帰的に探索
    }
    t++;
    a[v].second = t;
}

int main(){
    cin >> n;
    Graph G(n);
    rep(i, n){
        cin >> u >> k;
        u--;
        rep(j, k){
            cin >> v;
            v--;
            G[u].insert(v);
        }
    }

    seen.assign(n, false);
    rep(i, n){
        if(seen[i] == false) dfs(G, i);
    }
    rep(i, n) cout << i+1 << ' ' << a[i].first << ' ' << a[i].second << endl;
    return 0;
}