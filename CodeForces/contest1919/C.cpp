#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t; cin >> t;
    rep(_,t){
        ll n; cin >> n; vector<ll> s(n); rep(i,n) cin >> s[i];
        ll x = LLONG_MAX, y = LLONG_MAX, ans = 0;
        rep(i,n){
            if(x>y) swap(x,y);
            if(s[i] <= x) x = s[i];
            else if(s[i] <= y) y = s[i];
            else{
                x = s[i]; ans++;
            }
        }
        cout << ans << endl; 
    }
}