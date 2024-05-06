#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


vector<vector<bool>>is_there(5001, vector<bool>(5001));
bool find(pair<int,int> p){
    if (p.first > 5000 || p.second > 5000 or p.first < 0 or p.second < 0)return false;
    else return is_there[p.first][p.second];
}
 