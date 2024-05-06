#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
    int h, w;
    vector<string> c(h);
    cin >> h >> w;
    rep(i, h) cin >> c[i];


    while(true){
        rep(i, h){
            bool era = true;
            rep(j, w){
                char tmp = c[i][posx];
                if(c[i][j] != tmp) era = false;
            }
            if(era){
                c[i].erase();
                posy++;
            }
            
        }
    }



}