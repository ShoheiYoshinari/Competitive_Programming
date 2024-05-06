#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  string s;
  cin >> s;
  map<vector<int>,long long> mp;
  vector<int> cnt(10,0);
//i = 0のとき
  mp[cnt]++;
//
  for(auto &nx : s){
    cnt[nx-'0']++;
    cnt[nx-'0']%=2;
    mp[cnt]++;
  }
  long long res=0;
  for(auto &nx : mp){
    long long x=nx.second;
    res+=(x*(x-1))/2;
  }
  cout << res << "\n";
  return 0;
}



//分からなかった部分 嬉しい列の見つけ方

//先頭から i 文字 ( 0≤i≤∣S∣ ) に x が出現した回数を 2 で割った余りを Ri,xとする。
//R_{i,x} ( x=0,1,...,9 )
//Ri=R j( i<j ) であれば S の i+1 文字目から j 文字目までを抜き出した列が嬉しい列
//Riが等しい i のうちから相異なる 2 つを選べば、その組に嬉しい列である区間が対応することになる。
