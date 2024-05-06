#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/*
int main() {
    string s;
    cin >> s;

    vector<int> ku;
    vector<char> alfa;

    rep(i, s.size()){
        if(s[i] == '('){
            ku.push_back(i);
        }else if(s[i] == ')'){
            int last = ku.back();
            for (int j = last; j < i; j++)
            {
                if(s[j] >= 'a' && s[j] <= 'z'){
                    alfa.erase(s[j]);
                }
            }
            ku.erase(ku.end()-1);
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            if(alfa.find(s[i]) != alfa.end()){
                cout << "No" << endl;
                return 0;
            }else{
                alfa.push_back(a[i]);
            }
        }
    }
    cout << "Yes" << endl;
}
*/

/* s[i] == ')' の時、for文を使っているため、TLEしてしまう
特定のアルファベットだけで文字列ｓを調べる。O(26 * 3*(10^5))
*/
int main(){
    string s;
    cin >> s;

    for (char i = 'a'; i < 'z'; i++){
        int cnt = 0; // 特定の文字数をカウント
        int dep = 0; // ()の深さ
        vector<int> cnt_d(s.size()); // ある深い位置に特定の文字があるかどうかの配列
        cnt_d[0] = 0;  
        rep(j, s.size()){
            if(s[j] == '('){
                //一段階深くする
                dep++;
                cnt_d[dep] = 0;
            }else if(s[j] == ')'){
                //一段階浅くし、その位置の文字数だけ減らす
                cnt -= cnt_d[dep];
                cnt_d[dep] = 0;
                dep--;
            }if(s[j] == i){
                if(cnt > 0){// 同じ文字が箱にあるならX
                    cout << "No" <<endl;
                    return 0;
                }else{ // ないならその位置の文字数と箱の中にある文字数を１増やす
                    cnt++;
                    cnt_d[dep]++;
                }
            }
        }
    }
    cout << "Yes" << endl;
} 