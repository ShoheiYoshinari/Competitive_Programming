#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={1,0,-1,1,-1,1,0,-1};
const double PI = acos(-1);

int x, n, a[100009];
// xが何番目にあるかを返す
int binary_search(int x){
    int pos = lower_bound(a+1, a+n+1, x) - a;
    if(pos <= n && a[pos] == x) return pos;
    return -1;
}

//***********************************************//

bool isOK(int index, int key){
    if(a[index] >= key) return true;
    else return false;
}

int Binary_search(int key){
    int ng = -1;
    int ok = (int)a.size();

    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;

        if(isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
