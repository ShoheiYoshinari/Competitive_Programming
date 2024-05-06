#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
vector<bool> seen(200009);
void dfs(const Graph &G, int v) {
    seen[v] = true; //v を訪問済みにする
    //v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // 移動先が訪問済みならスルー
        dfs(G, next_v); // 再帰的に探索
    }
    if(v == 1) return;
    cout << v << ' '; 
}
int main(){
    int n, c, p;
    cin >> n;

    Graph G(200009);
    rep(i, n){
        cin >> c;
        rep(j, c){
            cin >> p;
            G[i].push_back(p);
        }
    }
    dfs(G, 1);
    cout << endl;
}