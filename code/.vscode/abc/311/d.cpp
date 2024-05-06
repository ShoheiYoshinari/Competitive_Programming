#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
// マス間の上下左右への移動を定義する
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

// マスを表す型。上から x 行目、左から y 列目のマスを {x, y}　で表すこととする
using pint = pair<int,int>;

int main() {
    // 入力
    int n, m;
    cin >> n >> m;
    vector<string> field(R);
    for (int i = 0; i < R; ++i) cin >> field[i];
    
    // 幅優先探索を実行するためのデータ構造
    // dist[x][y] はスタートマスからマス (x, y) までの最短路の長さ
    queue<pint> que;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    int cnt = 0;
    // 初期条件
    que.push({2, 2});
    dist[sx][sy] = 0;
    cnt++;    
    // 幅優先探索をスタート
    while (!que.empty()) {
        // 現在地はマス (x, y)
        auto [x, y] = que.front();
        que.pop();
        
        // 4 方向への移動を試す
        for (int dir = 0; dir < 4; ++dir) {
            int x2 = x + dx[dir];
            int y2 = y + dy[dir];
            
            // 新たなマスが場外の場合はダメ
            if (x2 < 0 || x2 >= R || y2 < 0 || y2 >= C) continue;
            
            // 新たなマスが壁の場合はダメ
            if (field[x2][y2] == '#') continue;
            
            // 新たなマスが訪問済みの場合はスキップ
            if (dist[x2][y2] != -1) continue;
            
            // 新たなマスを訪問する
            que.push({x2, y2});
            dist[x2][y2] = dist[x][y] + 1;
        }
    }
    cout << dist[tx][ty] << endl;
}