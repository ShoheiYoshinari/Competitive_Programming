#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int main(){
    int n, x;
    while(true){
        cin >> n >> x;
        if(n == 0 && x == 0) break;

        int cnt = 0;

        rep(i, n){
            rep(j, n){
                rep(k, n){
                    if(i != j && j != k && k != i){
                        if(i + j + k == x) cnt++;
                    }
                }
            }
        }
        cout << cnt / 6 << endl;
    }
    return 0;
}
