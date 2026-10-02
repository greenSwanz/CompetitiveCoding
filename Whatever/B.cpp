#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,m,k; cin >> n >> m >> k;
    // n piers //k queries;
    vector<bool> in(m, false); map<ll,ll> total;
    vector<ll> inl(m); 
    rep(i,k){
        ll p,c; cin >> p >> c; p--; c--;
        if(in[c]) { in[c] = false;
        if(inl[c] == p) total[c] += 100;
        else total[c] += abs(inl[c] - p);
        continue;
    }
    in[c] = true; inl[c] = p;
    }
    rep(i,m){
        if(in[i]) total[i] += 100;
    }
    rep(i,m){
        cout << total[i] << " ";
    }
    cout << endl;
}