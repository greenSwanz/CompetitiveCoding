#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll h1,d1,t1,h2,d2,t2;
    cin >> h1 >> d1 >> t1;
    cin >> h2 >> d2 >> t2;
    ll k1 = (((h2 + d1 - 1) / d1) - 1) * t1;
    ll k2 = (((h1 + d2 - 1) / d2) -1) * t2;
    if(k1 > k2) {cout << "player two" << endl; return 0;}
    if(k2 > k1) {cout << "player one"; return 0;}
    cout << "draw" << endl;


}