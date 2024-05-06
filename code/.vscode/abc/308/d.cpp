#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

string snuke = 'snuke';
void move(int i, int j){
    int ni, nj;
    if(i < 0 || i >= h || j < 0 || j >= w){
        return ;
    }
    if(i = h-1 && j = w-1){
        cout << "Yes" << endl;
        return 0;
    }
    ni = i;
    nj = j-1;
    if(ni >= 0){
        if(s[i][j])
    }

}
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, n) cin >> s[i];



}