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

int main() {
    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    vector<pair<ll, ll>> e;
    rep(i, n){
        if(s[i] == '1') e.push_back({x[i], 1});
        else e.push_back({x[i], 0});
    }
    sort(all(e));

    vector<ll> tasu;
    ll ans = 0;
    rep(i, n){
        if(e[i].second == 1){
            tasu.push_back(e[i].first+t);
        }else{
            auto res = lower_bound(tasu.begin(), tasu.end(), e[i].first-t) - tasu.begin();
            //cout << res << endl;
            ans += tasu.size() - res;
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;

}