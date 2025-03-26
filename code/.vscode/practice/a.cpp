#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
INIT(){
std::ios::sync_with_stdio(false);
std::cin.tie(0);
cout << fixed << setprecision(20);
}
}INIT;

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> b(n+1), s(n+2);
    b[0] = a[0] - 1;
    rep(i, 1, n) b[i] =  b[i-1] + (a[i] - a[i-1] - 1);
    b[n] = 1000000000000000000ll - a[n-1] - 1;

    s[0] = 0;
    rep(i, 1, n+2) s[i] = s[i-1] + b[i-1];

    rep(i, 0, n+2) cout << s[i] << ' ';
    cout << endl;
    rep(i, q){
        ll k;
        cin >> k;
        auto it = lower_bound(all(s), k) - s.begin();
        if(it == 1){
            cout << k << endl;
        }else{
            cout << a[it-1] + k-s[it] << endl;
        }
    }
}