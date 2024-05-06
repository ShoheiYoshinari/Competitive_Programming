#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> ice, fla;
    rep(i, n){
        int f, s;
        cin >> f >> s;
        ice.push_back(make_pair(s, f));
        fla.push_back(make_pair(f, s));
    }

    long long difmax = -1, samemax = -1;
    sort(ice.begin(), ice.end());
    reverse(ice.begin(), ice.end());
    sort(fla.begin(), fla.end());

    rep(i, n-1){
        if(ice[0].second != ice[i+1].second){
            difmax = ice[0].first + ice[i+1].first;
            break;
        }
    }
    rep(i, n-1){
        if(fla[i].first == fla[i+1].first) samemax = max(samemax, fla[i].second / 2 + fla[i+1].second);
    }

    cout << max(difmax, samemax) << endl;
}