#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define fore(i, a) for(auto &i : a)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, q, ss, t;
vector<int> a;

int binary_search(int x){
    int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
    if(pos <= n && a[pos] == x) return pos;
    return -1;
}

int main(){
    cin >> n;
    rep(i, n){
        cin >> ss;
        a.push_back(ss);
    }

    cin >> q;
    int ans = 0;
    rep(i, q){
        cin >> t;
        if(binary_search(t) != -1) ans++;
    }
    cout << ans << endl;
    return 0;
}