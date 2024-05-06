#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    string s;
    cin >> s;
    long long ans = 0;
    for (double i = 0; i < s.size(); i++)
    {
        long long x = 0;
        if('A' <= s[i] && s[i] <= 'Z') x = s[i] - 'A' + 1;
        ans += x * pow(26, (s.size() - i - 1));
    }
    cout << ans << endl;
}