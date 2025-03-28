#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    // 市、点数、市と点数の位置
    vector<tuple<string, int, int>> vs;
    rep(i, n){
        string s;
        int p;
        cin >> s >> p;
        // 点数が大きい順になるようにマイナスをつける
        vs.emplace_back(s, -p, i+1);
    }
    sort(vs.begin(), vs.end());
    rep(i, n){
        auto[s, p, id] = vs[i];
        cout << id << endl;
    }
    return 0;
}