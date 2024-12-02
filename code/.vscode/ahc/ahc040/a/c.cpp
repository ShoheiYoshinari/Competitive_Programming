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

struct Rectangle {
    int idx;
    int width, height;
};

int w, h;

pair<int, int> query(const vector<tuple<int, int, char, int>>& prdb) {
    cout << prdb.size() << endl;
    for (const auto& [p, r, d, b] : prdb) {
        cout << p << ' ' << r << ' ' << d << ' ' << b << endl;
    }
    cin >> w >> h;
    return {w, h};
}

int main() {
    int N, T, sigma;
    cin >> N >> T >> sigma;
    vector<Rectangle> rects(N);
    rep(i, N) {
        cin >> rects[i].width >> rects[i].height;
        rects[i].idx = i;
    }

    // 幅が小さい順に並べ替え
    sort(rects.begin(), rects.end(), [](const Rectangle& a, const Rectangle& b) {
        return max(a.width, a.height) < max(b.width, b.height);
    });

    rep(t, T) {
        vector<tuple<int, int, char, int>> prdb;

        int x = 0, y = 0; // 現在の配置座標
        int max_row_h = 0; // 現在の行の最大高さ
        int wari = (int)(sqrt(N));

        for (auto& rect : rects) {
            int cur_width = rect.width;
            int cur_height = rect.height;
            int rotate = 0;

            // 長辺を縦にして正方形に近づける
            if (cur_width < cur_height) {
                swap(cur_width, cur_height);
                rotate = 1;
            }

            // 現在の行に収まらない場合、次の行へ
            if (x + cur_width > w || t%wari == N-1) {
                x = 0;
                y += max_row_h;
                max_row_h = 0; // 新しい行の最大高さをリセット
            }

            // 新しい行にも収まらない場合、次の列へ（無駄な空きスペースを防ぐ）
            if (y + cur_height > h) {
                break; // 配置不能
            }

            // 配置情報を登録
            prdb.emplace_back(rect.idx, rotate, 'L', x);
            x += cur_width;
            chmax(max_row_h, cur_height);
        }

        auto [w, h] = query(prdb);
        W = w; // 得られた幅と高さを更新
        H = h;
    }

    return 0;
}