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
template<class T> bool chmin(T& a, T b) { return (a > b) ? (a = b, true) : false; }
template<class T> bool chmax(T& a, T b) { return (a < b) ? (a = b, true) : false; }
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct INIT {
    INIT() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(20);
    }
} INIT;

int W, H;
struct Rectangle {
    int idx;
    int width, height;
};

pair<int, int> query(const vector<tuple<int, int, char, int>>& prdb) {
    cout << prdb.size() << endl;
    for (const auto& [p, r, d, b] : prdb) {
        cout << p << ' ' << r << ' ' << d << ' ' << b << endl;
    }
    cin >> W >> H;
    return {W, H};
}

int main() {
    int N, T, sigma;
    cin >> N >> T >> sigma;
    vector<Rectangle> wh(N);
    rep(i, N) {
        cin >> wh[i].width >> wh[i].height;
        wh[i].idx = i;
    }

    rep(t, T) {
        vector<tuple<int, int, char, int>> prdb;

        int x = 0, y = 0, max_row_h = 0;
        int row = 0;

        rep(i, N) {
            int cur_width = wh[i].width;
            int cur_height = wh[i].height;
            int r = 0;

            bool can_rotate = (x + wh[i].height < H);
            if (cur_width > cur_height && can_rotate) {
                swap(cur_width, cur_height);
                r = 1;
            }

            if (x + cur_width >= 1e6) {
                x = 0;
                y += max_row_h;
                max_row_h = cur_height;
                ++row;
            }

            prdb.emplace_back(wh[i].idx, r, 'U', (row%4 == 0 ? -1 : row%4));

            x += cur_width;
            chmax(max_row_h, cur_height);
        }
        auto [w, h] = query(prdb);
    }
    return 0;
}
