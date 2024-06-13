#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

string long_to_base(long long n, long long p){
    string ans;
    while(n>0){
        char c = ((n%p)+'0');
        ans = c + ans;
        n /= p;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;

    int cnt = 0;
    while(n){
        string b8 = long_to_base(n, 8);
        string b10 = to_string(n);
        n--;
        
        bool ok1 = false, ok2 = false;
        rep(i, b8.size()) if(b8[i] == '7') ok1 = true;
        rep(i, b10.size()) if(b10[i] == '7') ok2 = true;

        if(ok1 || ok2) continue;
        cnt++;
    }
    cout << cnt << endl;
}