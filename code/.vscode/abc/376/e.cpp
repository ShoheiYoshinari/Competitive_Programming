#include <bits/stdc++.h>
using namespace std;
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
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

void solve(ll n, ll k, vector<ll>& a, vector<ll>& b){
    vector<pair<long long, int>> AB;
    rep(i, n) AB.push_back({(ll)a[i]*b[i], i});
    sort(AB.begin(), AB.end());

    ll sum_B = 0;
    ll max_A = 0;
    rep(i, k){
        int idx = AB[i].second;
        max_A = max(max_A, a[idx]);
        sum_B += b[idx];
    }
    cout << max_A * sum_B << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];

        solve(n, k, a, b);
    }
    return 0;
}