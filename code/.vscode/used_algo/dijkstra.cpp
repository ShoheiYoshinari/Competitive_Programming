#include<bits/stdc++.h>
using namespace std;
#define rep(i, s) for(int i = 0; i < (int)s; i++)
#define rep2(s, v, t) for(int s = (int)v; s <= (int)t; s++)

int n, m, a[100009], b[100009], c[100009];
vector<pair<int, int> > G[100009];

int cur[100009]; bool ok[100009];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

int main(){
    cin >> n >> m;
    rep(i, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(make_pair(b[i], c[i]));
        G[b[i]].push_back(make_pair(a[i], c[i]));
    }

    rep(i, n) ok[i] = false;
    rep(i, n) cur[i] = 2000000000;

    cur[0] = 0;
    Q.push(make_pair(cur[0], 0));

    while(!Q.empty()){
        int pos = Q.top().second; Q.pop();

        if(ok[pos] == true) continue;

        ok[pos] = true;
        rep(i, G[pos].size()){
            int nex = G[pos][i].first;
            int cost = G[pos][i].second;
            if(cur[nex] > cur[pos] + cost){
                cur[nex] = cur[pos] + cost;
                Q.push(make_pair(cur[nex], nex));
            }
        }
    }

    rep(i, n){
        if(cur[i] == 2000000000) cout << "-1" << endl;
        else cout << cur[i] << endl;
    }

    return 0;


}