#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;
    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N+2);
    for (int i = 1; i <= M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // BFS のためのデータ構造
    vector<int> dist(N+1, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;
    // 初期条件 (頂点 0 を初期ノードとする)
    dist[1] = 0;
    que.push(1); // 0 を橙色頂点にする
    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    sort(dist.begin(), dist.end());

    for (int v = 1; v <= N; ++v) {
        if(dist[v] == dist[v+1] ) {
            cout << "No" << endl;
            return 0;
        } 
    }
    for (int i = 1; i <= N; ++i) {
        if(dist[i] == N - 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;   
}
