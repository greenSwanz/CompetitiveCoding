#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K; cin >> N >> M >> K;
    vector<ll> cumsum(N,0); vector<ll> A(N);
    rep(i,N) cin >> A[i];
    rep(i,N){
        if(A[i] + cumsum[max(i-1,0LL)] - ((i - M < 0) ? 0 : cumsum[max(i-M,0LL)]) <= K ) {
            cout << "Yes" << endl; cumsum[i] = cumsum[max(0LL,i-1)] + A[i];}
        else{cout << "No" << endl; cumsum[i] = cumsum[max(0LL,i-1)];}
    }
}