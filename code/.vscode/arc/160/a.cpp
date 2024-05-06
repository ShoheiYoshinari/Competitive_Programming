#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<int>> aa(n^2, vector<int>(n));
    int k = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            aa[k].push_back(reverse(a + i, a + j));
            k++;
        }
    }
    sort(aa[].begin(), aa[].end());
    rep(i, n){
        cout << aa[k][i] << ' ';
    }
    cout << endl;

}