#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> cols(M,-1);
    rep(i,N){
        ll C,S;
        cin >> C >> S;
        cols[C-1] = max(S,cols[C-1]);
    }   
    rep(i,M) cout << cols[i] << " ";
    
}