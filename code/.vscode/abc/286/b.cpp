#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    string x;
    cin >> N >> x;

    for(int i = 0; i < N; i++)
    {
        cout << x.at(i);
        if (i == N - 1) // これがないと i = N の時 i + 1番目の文字を調べることになるから
        {
            break;
        }
        if(x.at(i) == 'n' && x.at(i + 1) == 'a')
          cout << "y";
                
    }
    cout << endl;
}