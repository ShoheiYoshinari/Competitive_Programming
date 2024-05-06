#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string to10(string s)
{
    long long ans = 0;
    rep(i, s.size()){
        n *= 2;
        if(s[i] == '1') n++;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    long long n;
    cin >> n;

    long long ans;
    string smin;

    rep(i, s.size()){
        if(s[i] == '?') smin.push_back('0');
        else smin.push_back(s[i]);
    }
    long long ans = to10(smin);
    if(ans > n) cout << "-1" << endl;
    else{
        rep(i, s.size()){
            if(s[i] == '?'){
                s[i] == '1';
                if(n < to10(s)) s[i] == '0';
            }
        }
    }
    cout << to10(s) << endl;


}