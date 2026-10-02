#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; cin >> N >> K; vector<ll> A(N); vector<ll> B(N); rep(i,N) {cin >> A[i];  B[i] = A[i] % K;}
   sort(B.begin(), B.end()); ll ans = B[N-1] - B[0];
    rep(i,N-1)  ans = min(ans, B[i] + K - B[i+1]); cout << ans << endl;
}