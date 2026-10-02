#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q; cin >> N >> Q;
    vector<ll> down(N+1,-1); vector<ll> up(N+1,-1); vector<ll> total(N+1,0);
    rep(i,Q){
        ll c,p; cin >> c >> p;
        if(down[c] != -1) {up[down[c]] = -1;}
        up[p] = c;
        down[c] = p;
    }
    repp(i,1,N+1){
        if(down[i] == -1){
            ll temp = up[i]; total[i]++;
            while(temp != -1) {temp = up[temp]; total[i]++;}
        }
    }
    repp(i,1,N+1) cout << total[i] << " ";
}