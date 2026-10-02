#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;
    map<ll,ll> m; set<ll> coords;
    ll cur = 0; ll dist = 0; ll cookies = 0;
    rep(i,N){
        ll temp; cin >> temp;
        coords.insert(temp);
        m[temp]++;
    }
    while(!coords.empty()){
        auto it = coords.lower_bound(cur);
        if(it == coords.end()){
            --it;
            dist += abs(cur - *it);
            cur = *it;
        }
        else if(it == coords.begin()){
            dist+= abs(*it- cur);
            cur = *it;
        }
        else { 
            ll vmax = *it;
            ll vmin = *prev(it);
            if(cur - vmin <= vmax - cur) {dist+= abs(cur - vmin); cur = vmin;}
            else{ dist+= abs(vmax - cur); cur = vmax;}
        }
        cookies += m[cur];
        coords.erase(cur);
    }
    cout << dist << endl;
}