#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(p) (p).begin(), (p).end()

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

ll n, x;

bool taskAchieve(ll W_target, vector<ll>& a, vector<ll>& p, vector<ll>& b, vector<ll>& q) {
    ll total_cost = 0;

    rep(i, n) {
        ll min_cost = LLONG_MAX;
        for (ll s = 0; s <= W_target / a[i]; s++) {
            ll remaining_capacity = max(0LL, W_target - s * a[i]);

            ll t = (remaining_capacity + b[i] - 1) / b[i];
            ll total = s * p[i] + t * q[i];

            min_cost = min(min_cost, total);
        }
        total_cost += min_cost;

        if (total_cost > x) return false;
    }

    return total_cost <= x;
}

int main() {
    cin >> n >> x;
    vector<ll> a(n), b(n), p(n), q(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    ll ans = 0;
    ll ok = -1, ng = 1e9 + 1;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (taskAchieve(mid, a, p, b, q)) {
            ans = mid;
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ans << endl; 
    return 0;
}
