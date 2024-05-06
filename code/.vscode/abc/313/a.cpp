#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;

    long long ans = 0;
    
    if(a >= k){
        cout << k << endl;
    }else if(a < k && k <= b + a){
        cout << a << endl;
    }else if(a + b < k && k <= a + b + c){
        cout << a - (k - a - b) << endl;
    }
}