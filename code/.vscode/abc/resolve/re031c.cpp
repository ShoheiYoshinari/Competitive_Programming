#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int takahashi = -10000000;

    rep(i, n){
        int aoki_place;
        rep(j, n){
            int aoki = -10000000, place = 51;
            int A = 0;
            if(i != j){
                if(i > j){
                    for(int k = j+1; k <= i; k+=2){
                        A += a[k];
                    }
                }else{
                    for(int k = i+1; k <= j; k+=2){
                        A += a[k];
                    }
                }
            }
            if(aoki <= A){
                aoki = A;
                if(place > j) place = j;
            }
            aoki_place = place;
        }

        int T = 0;
        if(i > aoki_place){
            for(int l = aoki_place; l <= i; l+=2){
                T += a[l];
            }
        }else{
            for(int l = i; l <= aoki_place; l+=2){
                T += a[l];
            }
        }
        if(takahashi < T) takahashi = T;

    }
    cout << takahashi << endl;
}
*/

const int INF = 1e9;

int n, a[60];
int main(void){
    cin >> n;
    rep(i, n) cin >> a[i];

    int ans = -INF;
    for (int i = 0; i < n; ++i){//takahashi
        int aoki_p, aoki_v = -INF, tmp_ans;
        for (int j = 0; j < n; ++j){//aokiがよい位置を探す
            if(i == j) continue;
            int l = min(i, j);
            int r = max(i, j);
            int cnt = 1, taka = 0, aoki = 0;
            for (int p = l; p <= r; ++p){
                if(cnt % 2 == 1){
                    taka += a[p];
                }else{
                    aoki += a[p];
                }
                cnt++;
            }
            //aokiが最高得点をとれるときをさがす
            if(aoki > aoki_v){
                aoki_p = j;
                aoki_v = aoki;
                tmp_ans = taka;//青木が最高得点となるときが、高橋の得点
            }
        }
        ans = max(ans, tmp_ans);
    }

    printf("%d\n", ans);
    return 0;
}