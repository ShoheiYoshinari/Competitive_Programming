#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int n,q;
    cin>>n>>q;
    set<pair<int, int>> follow;

    rep(i, q){
        int t,a,b;
        cin>>t>>a>>b;
        if(t == 1){
            follow.insert(make_pair(a, b));
        }else if(t == 2){
            follow.erase(make_pair(a, b));
        }else{
            if((follow.find(make_pair(a, b)) != follow.end()) 
            && follow.find(make_pair(b, a)) != follow.end()) cout << "Yes" <<endl;
            else cout << "No" <<endl;
        }        
    }
    return 0;
}