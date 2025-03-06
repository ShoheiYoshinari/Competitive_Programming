#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

struct Pos { int r, c; };
struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const { return cost < other.cost; }
};

struct Solver {
    int N, M, K, T, money;
    vector<Pos> home, workplace;
    vector<vector<int>> grid;
    vector<Edge> edges;
    vector<int> parent, rank;
    vector<Pos> stations;
    set<pair<int, int>> occupied;
    
    Solver(int N, int M, int K, int T, vector<Pos>& home, vector<Pos>& workplace)
        : N(N), M(M), K(K), T(T), home(home), workplace(workplace), money(K) {
        grid.assign(N, vector<int>(N, -1));
        parent.resize(N * N);
        rank.resize(N * N, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    bool canPlace(int r, int c) {
        return occupied.find({r, c}) == occupied.end();
    }

    void buildRail(Pos a, Pos b) {
        if (money < 1 || !canPlace(a.r, a.c) || !canPlace(b.r, b.c)) return;
        money--;
        cout << "1 " << a.r << " " << a.c << "\n";
        occupied.insert({a.r, a.c});
    }

    void constructPath() {
        if (stations.size() < 2) return;
        for (size_t i = 0; i < stations.size() - 1; i++) {
            buildRail(stations[i], stations[i + 1]);
        }
    }

    void solve() {
        for (int i = 0; i < M; i++) {
            if (money < 1) break;
            if (canPlace(home[i].r, home[i].c)) {
                cout << "0 " << home[i].r << " " << home[i].c << "\n";
                money--;
                stations.push_back(home[i]);
                occupied.insert({home[i].r, home[i].c});
            }
            if (stations.size() >= 2) constructPath();
            if (money < 1) break;
            if (canPlace(workplace[i].r, workplace[i].c)) {
                cout << "0 " << workplace[i].r << " " << workplace[i].c << "\n";
                money--;
                stations.push_back(workplace[i]);
                occupied.insert({workplace[i].r, workplace[i].c});
            }
            if (stations.size() >= 2) constructPath();
        }
        while (T-- > 0) cout << "-1\n";
    }
};

int main() {
    int N, M, K, T;
    cin >> N >> M >> K >> T;
    vector<Pos> home(M), workplace(M);
    for (int i = 0; i < M; i++) {
        cin >> home[i].r >> home[i].c >> workplace[i].r >> workplace[i].c;
    }
    Solver solver(N, M, K, T, home, workplace);
    solver.solve();
    return 0;
}
