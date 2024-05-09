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

int n, q, t;

int main(){
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> st;
    rep(i, 1<<n){
        int sum = 0;
        rep(j, n){
            int wari = 1 << j;
            if((i/wari)%2 == 1) sum += a[j];
        }
        st.insert(sum);
    }

    cin >> q;
    rep(i, q){
        cin >> t;
        if(st.find(t) != st.end()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}