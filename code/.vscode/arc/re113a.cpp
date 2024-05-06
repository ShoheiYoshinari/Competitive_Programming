#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
int main() {
    int k;
    cin >> k;

    long long ans = 0;
    for(int i = 1; i < k; i++){
        for(int j = 1; ;j++){
            if(i * j > k) break;
            for(int l = 1; ; l++){
                if(i * j * l > k) break;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
