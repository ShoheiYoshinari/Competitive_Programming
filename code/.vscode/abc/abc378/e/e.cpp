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

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
        a[i] %= m;
    }

    // 順序を保証しないハッシュマップを使用
    unordered_map<ll, ll> mod_count;
    ll total_sum = 0;
    ll ans = 0;

    // 各要素の加算
    for (ll j = 0; j < n; ++j) {
        // 現在の要素を累積和に追加
        total_sum += a[j];
        // 現在の要素に基づくモジュロのカウント
        ans += (a[j] * j - total_sum) % m;
        ans += mod_count[(total_sum % m)]; // 既存の mod カウントを加算
        // モジュロを更新
        mod_count[(total_sum % m)]++;
    }
    
    cout << ans << endl;
}