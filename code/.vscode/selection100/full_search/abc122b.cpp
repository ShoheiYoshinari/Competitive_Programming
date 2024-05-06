#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int main(){
    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    string ACGT = "ACGT";

    rep(i, s.size()){
        bool ok = false;
        rep(j, ACGT.size()){
            if(s[i]==ACGT[j]) ok = true;
        }
        if(ok)cnt++;
        else cnt = 0;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}