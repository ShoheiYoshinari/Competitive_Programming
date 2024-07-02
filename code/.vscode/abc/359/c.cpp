#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

int main() {
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    if(sy < ty){
        //guusuu
        if(sx%2 == 0) if(sy%2 == 0) if(tx > sx) sx++;
        if(sx%2 == 1) if(sy%2 == 0) if(sx > tx) sx--;
        if(tx%2 == 0) if(ty%2 == 0) if(sx > tx) tx--;
        if(tx%2 == 1) if(ty%2 == 0) if(tx > sx) tx++;
        //kisuu
        if(sx%2 == 0) if(sy%2 == 1) if(sx > tx) sx--;
        if(sx%2 == 1) if(sy%2 == 1) if(tx > sx) sx++;
        if(tx%2 == 0) if(ty%2 == 1) if(tx > sx) tx++;
        if(tx%2 == 1) if(ty%2 == 1) if(sx > tx) tx--;
    }else if(sy > ty){
        //guusuu
        if(sx%2 == 0) if(sy%2 == 0) if(tx < sx) sx--;
        if(sx%2 == 1) if(sy%2 == 0) if(sx < tx) sx++;
        if(tx%2 == 0) if(ty%2 == 0) if(sx < tx) tx++;
        if(tx%2 == 1) if(ty%2 == 0) if(tx < sx) tx--;
        //kisuu
        if(sx%2 == 0) if(sy%2 == 1) if(sx < tx) sx++;
        if(sx%2 == 1) if(sy%2 == 1) if(tx < sx) sx--;
        if(tx%2 == 0) if(ty%2 == 1) if(tx < sx) tx--;
        if(tx%2 == 1) if(ty%2 == 1) if(sx < tx) tx++;
    }else{
    }

    ll tate = abs(sy - ty);
    ll yoko = abs(sx - tx);

    if(tate >= yoko){
        cout << tate << endl;
    }else{
        cout << tate + (tate - yoko) << endl;
    }
    return 0;
}