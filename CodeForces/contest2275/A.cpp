#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll t; cin >> t;
    rep(_,t){
        ll x, y, r; cin >> x >> y >> r;
        cout << x + r << " " << y << endl;
    }
}