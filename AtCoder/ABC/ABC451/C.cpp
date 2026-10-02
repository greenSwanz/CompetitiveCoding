#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    map<ll,ll> m; ll total = 0;
    ll Q; cin >> Q;
    rep(i,Q){
        ll a,h; cin >> a >> h;
        if(a==1) {m[h]++; total++;}
        else {
            auto it = m.begin();
            while (it != m.end() && it->first <= h) {
                total -= it->second; it = m.erase(it);
            }
        }
        cout << total << endl;
    }
}