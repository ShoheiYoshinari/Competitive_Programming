#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> ass(m);
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        ass[i].resize(c);
        for(auto& x : ass[i]) cin >> x;
    }

     // {0, 1, ..., n-1} の部分集合の全探索
     // bits全探索　O(N*2^N) (n <= 20)
    for (int bit = 0; bit < (1<<m); ++bit) { // O(2^10)
        set<int> S;
        for (int i = 0; i < m; ++i) { // O(10)
            if ((bit >> i) & 1) { // 列挙に 1 が含まれるか
                for (auto& x : ass[i])
                {
                    S.insert(x);
                }  
            }
        }
        if(S.size() == n) ans++;
    }
    cout << ans << endl;
    



        
}
