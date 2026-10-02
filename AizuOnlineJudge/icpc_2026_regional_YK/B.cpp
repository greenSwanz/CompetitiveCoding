#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,d; cin >> n >> d;
    while(n > 0 && d > 0){
        vector<ll> x(n);
        rep(i,n) cin >> x[i];
        sort(x.begin(),x.end());
        ll total = 0;
        auto it = x.begin(); 
        while((it != x.end())){
            ll limit = *it + (2*d);
            it = upper_bound(it,x.end(),limit);
            total++;
        }
        cout << total << endl;
        cin >> n >> d;
    }    
}