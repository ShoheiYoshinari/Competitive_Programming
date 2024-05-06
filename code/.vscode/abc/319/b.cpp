#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> candi;
    rep2(i, 1, 10){
        if(n%i == 0) candi.push_back(i);
    }
    rep(i, n+1){
        bool ck = false;
        for(auto p : candi){
            if(i % (n / p) == 0){
                cout << p;
                ck = true;
                break;
            }
        }
        if(!ck) cout << '-';
    }
    cout << endl;
}