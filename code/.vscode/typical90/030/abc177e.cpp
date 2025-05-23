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

const ll MAX = 1000009;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> num(MAX, 0);
    rep(i, n) num[a[i]]++;
    bool coprime = true;
    for(int a = 2; a < MAX; a++){
        ll sum = 0;
        for(int b = a; b < MAX; b+=a) sum += num[b];
        if(sum > 1) coprime = false;
    }
    if(coprime){
        cout << "pairwise coprime" << endl;
        return 0;
    }

    ll g = 0;
    rep(i, n) g = gcd(g, a[i]);
    if(g == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    return 0;

}