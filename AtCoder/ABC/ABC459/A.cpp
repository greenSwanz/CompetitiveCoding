#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string A = "HelloWorld";

    int X;
    cin >> X;
    rep(i,10){
        if(i != X-1){
            cout << A[i];
        }
    }
}