#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        st.insert(a);
    }   
    // k,n で二重ループを用いると、9 * 1e10 となり1e9を超えてしまうためx
    /*
    for (int i = 0; i < k; i++){
        bool judg = false;
        for (int j = 0; j < n; j++){
            if(a[j] == i){
                judg = true;
                continue;
            }     
        }
        if(judg == false){
            cout << i << endl;
            return 0;
        }
    }
    cout << k << endl;
    */

   for (int i = 0; i < k; i++)
   {
    if(st.find(i) == st.end()){ // 文字列stの中に任意のiが存在しないとき
        cout << i << endl;
        return 0;
    }
   }
   cout << k << endl;
   return 0;
}
   

   