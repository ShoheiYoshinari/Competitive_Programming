#include <bits/stdc++.h>
using namespace std;
/* int main() {
    int n;
    int maxans = 0, minans = 10^9;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxans = max(maxans, a[i]);
        minans = min(minans, a[i]);
    }
    cout << maxans - minans << endl;
} */

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  sort(A.begin (), A.end());
  int ans = A[N-1] - A[0];
  cout << ans << endl;
  return 0;
}