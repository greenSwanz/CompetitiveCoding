#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; ll total = 0; ll h = 0,t=0,u=0;
    rep(i,N){
      ll a; cin >> a; a = (a%1000 == 0) ? 0 : (1000 - (a%1000));
      h += a/100; a%= 100;
      t += a/10; a %= 10;
      u += a;
    }
    cout << u << " " <<  t << " " << h << endl;


}