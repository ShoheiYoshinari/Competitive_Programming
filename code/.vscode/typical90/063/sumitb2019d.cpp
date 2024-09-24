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

const int pin = 1000;

int main() {
    ll n;
    string s;
    cin >> n >> s;

    ll cnt = 0;
    rep(i, pin){
        string str = to_string(i);
        if(str.size() == 1) str = "00" + str;
        if(str.size() == 2) str = "0" + str;
        ll pos = 0;
        rep(j, n){
            if(s[j] == str[pos]) pos++;
            if(pos == 3){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}