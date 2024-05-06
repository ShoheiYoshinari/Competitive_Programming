#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int m, d[109], sum = 0;
    cin  m;
    rep(i, m){
        cin >> d[i];
        sum += d[i];
    }

    int mid = (sum + 1)/2;
    int month = 1;
    rep(i, m){
        if(mid - d[i] <= 0){
            cout << month << ' ' << mid << endl;
            return 0;
        }else{
            mid -= d[i];
            month++;
        }
    }




}