#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

// グラフ内の各頂点からの最短距離をBFSで計算する
vector<vector<int>> calculateDistances(const Graph& G, int n) {
    vector<vector<int>> dist(n, vector<int>(n, -1)); // 各頂点からの距離を格納
    for (int i = 0; i < n; ++i) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0; // 自分自身への距離は0
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto next_v : G[v]) {
                if (dist[i][next_v] == -1) { // まだ訪れていないなら距離を更新
                    dist[i][next_v] = dist[i][v] + 1;
                    q.push(next_v);
                }
            }
        }
    }
    return dist;
}

// コスト行列に基づいて、グラフのエッジ追加・削除コストを計算
int calculateCost(const Graph& G, const Graph& H, const vector<vector<int>>& costMatrix, const vector<int>& perm) {
    int cost = 0;
    int n = G.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int u = perm[i];
            int v = perm[j];
            
            // G と H の辺の有無を比較
            bool edgeG = find(G[i].begin(), G[i].end(), j) != G[i].end();
            bool edgeH = find(H[u].begin(), H[u].end(), v) != H[u].end();
            
            // 辺の有無が異なる場合にコストを加算
            if (edgeG != edgeH) {
                cost += costMatrix[i][j];
            }
        }
    }
    return cost;
}

int main() {
    int n, mg, mh;
    cin >> n >> mg;
    Graph G(n), H(n);

    // グラフ G を入力
    for (int i = 0; i < mg; ++i) {
        int u, v;
        cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cin >> mh;
    // グラフ H を入力
    for (int i = 0; i < mh; ++i) {
        int u, v;
        cin >> u >> v; u--, v--;
        H[u].push_back(v);
        H[v].push_back(u);
    }

    // コスト行列を入力
    vector<vector<int>> costMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> costMatrix[i][j];
        }
    }

    // グラフ G と H の各頂点からの距離を計算
    auto distG = calculateDistances(G, n);
    auto distH = calculateDistances(H, n);

    int minCost = INT_MAX;
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);

    // 順列をすべて試して、最小コストを計算
    do {
        int cost = calculateCost(G, H, costMatrix, perm);
        minCost = min(minCost, cost);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << minCost << endl;

    return 0;
}
