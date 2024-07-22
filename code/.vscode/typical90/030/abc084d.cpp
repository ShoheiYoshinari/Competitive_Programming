#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

const int MAX = 100009;

bool isPrime(int x){
   int i;
   if(x < 2)return 0;
   else if(x == 2) return 1;
   if(x%2 == 0) return 0;
   for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
   return 1;
}

int main() {
    int q;
    cin >> q;

    int p[MAX];
    rep(i, 1, MAX){
        if(isPrime(i) && isPrime((i+1)/2)) p[i]++;
    }

    int s[MAX];
    s[0] = 0;
    rep(i, 1, MAX){
        s[i] = s[i-1] + p[i];
        //cout << s[i] << endl;
    }
    
    rep(i, q){
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}