#include <iostream>
#include <vector>
using namespace std;

class BIT {
private:
    vector<int> bit;
    int n;

public:
    // コンストラクタ
    BIT(int size) {
        n = size;
        bit.resize(n + 1, 0);  // BITのサイズはn+1
    }

    // 更新操作 (i番目の位置に1を加える)
    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    // 累積和を求める (1番目からidx番目までの合計を求める)
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    // k番目の位置を探す (累積和がkである位置を返す)
    int find_kth(int k) {
        int low = 1, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (query(mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    BIT bit(N);  // BITのインスタンス作成
    vector<int> result(N);

    // 1からNまでの順番で処理
    for (int i = 1; i <= N; ++i) {
        int pos = P[i-1];  // P[i] は1-based index
        int insert_pos = bit.find_kth(pos);  // k番目の位置を求める
        result[insert_pos - 1] = i;  // 挿入
        bit.update(insert_pos, 1);  // BITの更新
    }

    // 結果を出力（末尾に空白を入れない）
    for (int i = 0; i < N; ++i) {
        cout << result[i];
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
