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
    int n;
    cin >> n;
    vector<pair<int,int>> red(n), blue(n);
    rep(i, n){
        int a, b; cin >> a >> b;
        red.emplace_back(a, b);
    }
    rep(i, n){
        int c, d; cin >> c >> d;
        blue.emplace_back(c, d);
    }

    sort(all(red));
    sort(all(blue));

    int ans = 0;
    rep(i, n){
        
    }
}