#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

using Graph = vector<vector<pair<int, int>>>;

pair<int, vector<int>> bfs_farthest(const Graph& G, int start) {
    int n = G.size();
    vector<int> dist(n, -1);
    queue<int> que;
    que.push(start);
    dist[start] = 0;
    
    int max_dist = 0;
    int farthest_node = start;
    
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        
        for (auto [nv, weight] : G[v]) {
            if (dist[nv] == -1) { // not visited
                dist[nv] = dist[v] + weight;
                que.push(nv);
                if (dist[nv] > max_dist) {
                    max_dist = dist[nv];
                    farthest_node = nv;
                }
            }
        }
    }
    
    return {farthest_node, dist};
}

pair<int, int> find_diameter(const Graph& G) {
    // Step 1: Find the farthest node from any starting node (let's start from node 0)
    pair<int, vector<int>> result1 = bfs_farthest(G, 0);
    int u = result1.first;
    
    // Step 2: Find the farthest node from u
    pair<int, vector<int>> result2 = bfs_farthest(G, u);
    int v = result2.first;
    
    // The distance between u and v is the diameter of the graph
    return {u, v};
}

bool dfs_find_path(const Graph& G, int v, int parent, int target, stack<int>& path) {
    if (v == target) {
        path.push(v);
        return true;
    }
    
    for (auto [nv, weight] : G[v]) {
        if (nv != parent) {
            if (dfs_find_path(G, nv, v, target, path)) {
                path.push(v);
                return true;
            }
        }
    }
    
    return false;
}

pair<int, vector<int>> longest_path(const Graph& G) {
    int n = G.size();
    vector<int> path;
    
    // Find any endpoint of the diameter (here, we find from node 0)
    pair<int, int> endpoints = find_diameter(G);
    int u = endpoints.first;
    int v = endpoints.second;
    
    // Find the path from u to v
    stack<int> path_stack;
    dfs_find_path(G, u, -1, v, path_stack);
    
    // Convert stack to vector for easier manipulation
    while (!path_stack.empty()) {
        path.push_back(path_stack.top());
        path_stack.pop();
    }
    
    return {u, path};
}

long long calculate_path_sum(const Graph& G, const vector<int>& path) {
    long long sum = 0;
    
    // Calculate sum of weights along the longest path
    for (int i = 1; i < path.size(); ++i) {
        int u = path[i - 1];
        int v = path[i];
        cout << u << ' ' << v << endl;
        
        bool is_on_longest_path = (u == path.front() && v == path.back()) || (v == path.front() && u == path.back());
        
        for (auto [nv, weight] : G[u]) {
            if (nv == v) {
                sum += weight;
                break;
            }
        }
        
        if (!is_on_longest_path) {
            // Use the weight directly from the edge (u, v)
            for (auto [nv, weight] : G[u]) {
                if (nv == v) {
                    sum += 2 * weight;
                    break;
                }
            }
        }
    }
    
    return sum;
}

int main() {
    int n;
    cin >> n;
    Graph G(n);
    
    // Input edges with weights
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Convert to 0-based index
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    
    // Calculate the longest path and its sum
    pair<int, vector<int>> result = longest_path(G);
    int start_node = result.first;
    vector<int>& path = result.second;
    
    // Output the longest path
    cout << "Longest path:";
    for (int node : path) {
        cout << " " << node + 1; // Convert back to 1-based index for output
    }
    cout << endl;
    
    // Calculate the sum of weights along the longest path
    long long longest_path_sum = calculate_path_sum(G, path);
    cout << "Sum of weights along the longest path: " << longest_path_sum << endl;
    
    return 0;
}
