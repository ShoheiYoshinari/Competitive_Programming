#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    unordered_map<int, int> count; // 各値の出現回数
    long long total = 0;
    int unique = 0;
    int right = 0;

    for (int left = 0; left < N; ++left) {
        // 右端を伸ばす処理
        while (right < N && (count[A[right]] == 0)) {
            count[A[right]]++;
            unique++;
            right++;
        }

        // 現在の区間の種類数を総和に加算
        total += unique;

        // 左端を動かす処理
        count[A[left]]--;
        if (count[A[left]] == 0) {
            unique--;
        }
    }

    cout << total << endl;

    return 0;
}
