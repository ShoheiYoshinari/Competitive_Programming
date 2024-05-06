#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int n;
    cin >> n;
    long long sum = 0;
    int x[n], y[n];
    rep(i, n) cin >> x[i] >> y[i];

    int yamp = -100000009,yam = -100000009;
    for(int i = 0; i < n; i++){
        if(x[i] == 1){
            while(x[i] != 0 || i != n-1){
                yam = max(yam, y[i]);
                i++;
            }
        }
        if(x[i] == 0){
            while(x[i] != 1 || i != n-1){
                if(y[i] > 0){
                    sum += y[i];   
                }
                yamp = max(yamp, y[i]);
                i++;    
            }

        }
        if(yamp != -100000009 && yam != -100000009){
            if(yam + yamp > 0){
                if(yamp < 0) sum += yam+yamp;
                else sum += yam;
                yam = -100000009;
                yamp = -100000009;
            }
        }
    }
    cout << sum << endl;




}