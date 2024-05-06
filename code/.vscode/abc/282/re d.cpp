#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

#define N 200001

vector<int> e[N];
vector<int> color(N, -1);
ull white = 0;
ull black = 0;

// 深さ優先探索（２部グラフであるかどうか）
bool dfs(int v, int cur_color)
{
	color[v] = cur_color;
    // 連結部分の白黒の頂点の個数
	if (cur_color == 0) {
		++white;
	} else {
		++black;
	}
	for (auto next_v : e[v]) {
        // 隣接した頂点が未探索でない
		if (color[next_v] != -1) {
            // 隣接した頂点が同じ色ならfalse
			if (color[next_v] == cur_color) {
				return false;
			}
			continue;
		}
            // 再帰的に（隣接した頂点を異なる色で）
		if (!dfs(next_v, 1 - cur_color)) {
			return false;
		}
	}

	return true;
}

int main()
{
	ull n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

        /* 頂点のペアの個数 N(N−1)/2 から、
        各連結成分の同じ色に塗られた頂点同士のペアの個数を引き、
        さらに、初めから辺で結ばれている頂点のペアの個数 M を引いた
        */

	ull result = (n * (n - 1))/ 2 - m;

    /*  連結部分ごとに２部グラフであるかどうか調べる
        異なる連結成分に属する頂点同士のペアについては、
        その間に辺を追加して得られるグラフは必ず二部グラフとなります。 
        （例えば、連結成分 A の黒い頂点と連結成分 B の黒い頂点を辺で結ぶ場合、連結成分 
        B の白と黒を反転すれば、辺を追加後のグラフに対する色分けが得られます。）
    */
	for (int i = 1; i <= n; ++i) {
		if (color[i] == -1) {
			white = 0;
			black = 0;
			if (dfs(i, 0)) {
				result -= white * (white - 1)/ 2;
				result -= black * (black - 1)/ 2;
			} else {
				cout << 0 << endl;
				return 0;
			}
		}
	}

	cout << result << endl;

	return 0;
}