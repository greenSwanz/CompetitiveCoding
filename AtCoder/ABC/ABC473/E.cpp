#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; vector<ll> A(N); rep(i,N) cin >> A[i]; ll left = 0; ll right = N; vector<ll> cumsum(N+1); cumsum[0] = 0;
    repp(i,1,N+1) cumsum[i] = cumsum[i-1] + A[i-1];
    while(left < right){
        if((cumsum[right] - cumsum[left]) % K == 0)
    }
}