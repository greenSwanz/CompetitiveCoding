#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M; cin >> N >> M; vector<ll> grapes(N,0); ll index = 0;
    while(M > 0){
        grapes[index % N] += 1; M--; index++;
    }
    rep(i,N){ cout << grapes[i] << endl;}
}