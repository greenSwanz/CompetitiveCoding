#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q; cin >> N >> Q;
    map<ll,set<ll>> less_than; map<ll,set<ll>> leq;
    rep(i,Q){
        ll t,u,v; cin >> t >> u >> v;
        if(t== 1) less_than[v].insert(u);
        if(t== 0) leq[v].insert(u);
    }
}