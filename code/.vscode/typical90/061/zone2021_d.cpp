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

int main() {
    string s;
    cin >> s;

    deque<char> t;
    bool reverse_flag = false;
    rep(i, s.size()){
        if(s[i] == 'R'){
            reverse_flag = !reverse_flag;
        }else{
            if(reverse_flag) t.push_back(s[i]);
            else t.push_front(s[i]);
        }
    }

    string tmp(all(t));
    if(reverse_flag) reverse(all(tmp));

    // Remove consecutive duplicates
    vector<char> ans;
    for (char c : tmp) {
        //ansの末尾とcが同じとき
        if (!ans.empty() && ans.back() == c) {
            ans.pop_back();
        } else {
            ans.push_back(c);
        }
    }
    rep(i, ans.size()) cout << ans[i];
    cout << endl;
    return 0;
}