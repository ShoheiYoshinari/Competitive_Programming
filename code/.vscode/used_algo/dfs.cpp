#include<bits/stdc++.h>
using namespace std;
#define rep(i, s) for(int i = 1;i <= (int)s; i++)
#define rep2(i, v, s) for(int i = (int)v; i < (int)s; i++)
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const double PI = acos(-1);

int n, m, a[100009], b[100009];
vector<int> G[100009];
bool visited[100009];

void dfs(int pos){
    visited[pos] = true;
    rep2(i, 0, G[pos].size()){
        int nex = G[pos][i];
        if(visited[nex] == false) dfs(nex);
    }
    return;
}

int main(){
    cin >> n >> m;
    rep(i, m){
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    rep(i, n) visited[i] = false;

    dfs(1);

    rep(i, n){
        if(visited[i] == false){
            cout << "The graph is not connected." << endl;
            return 0;
        }
    }
    cout << "The graph is connected." << endl;
    return 0;
}

