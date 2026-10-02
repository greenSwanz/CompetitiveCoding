#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll X,Y;
        cin >> X >> Y;
        if(X % Y != 0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
        
    }
}