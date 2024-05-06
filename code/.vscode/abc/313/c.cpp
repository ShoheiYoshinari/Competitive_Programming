#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using Graph = vector<vector<int>>;
vector<bool> seen(200009);
void dfs(const Graph &G, int v) {
    seen[v] = true; //v を訪問済みにする
    cout << v+1 << ' ';
    //v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // 移動先が訪問済みならスルー
        dfs(G, next_v); // 再帰的に探索
        cout << v+1 << ' ';
    }
}

int main(){
    int n;
    cin >> n;
    Graph G(n);
    rep2(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i ,n) sort(G[i].begin(), G[i].end());

    dfs(G, 0);
    cout << endl;
    return 0;
}

