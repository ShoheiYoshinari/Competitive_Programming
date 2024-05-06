#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    long long ans = 100000000000;
    for (int ai = 0; ai < n; ai++)
    {
        long long now = (long long) a * ai;
        string t = s;
        rotate(t.begin(), t.begin()+ai, t.end());     
        for (int i = 0,j = n-1;i < j; i++,j--)
         {
            if(t[i] != t[j]){
            now += b;
            }
         }
         ans = min(ans,now);
    }
    cout << ans << endl;
}

    