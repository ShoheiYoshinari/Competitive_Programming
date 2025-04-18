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

int n, m;
vector<vector<int>> ans;

void generate(int s, vector<int>& now) {
    if (now.size() == n) {
        ans.push_back(now);
		return ;
    }

    for (int next = s + 10; next <= m; ++next) {
        now.push_back(next);
        generate(next, now);
        now.pop_back();
    }
}

int main() {
    cin >> n >> m;
    vector<int> now;

    for (int s = 1; s <= m; ++s) {
        now.push_back(s);
        generate(s, now);
        now.pop_back();
    }

    cout << ans.size() << endl;
    for (auto& a : ans) {
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}