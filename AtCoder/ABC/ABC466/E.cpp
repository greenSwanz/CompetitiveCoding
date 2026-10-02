#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; cin >> N >> K;
    ll A[N], B[N]; rep(i,N) cin >> A[i] >> B[i];
    vector<vector<ll>> dp(N,vector<ll>(K*2+1,0));
    dp[0][0] = A[0]; dp[0][1] = B[0];
    repp(i,1,N){
        rep(j,2*K +1){
            if(j == 0) { dp[i][j] = dp[i-1][j] + A[i]; continue; }
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + ((j % 2 == 0) ?  A[i] : B[i]);
        }
    }
    ll ans = 0;
    rep(i,2*K+1) ans = max(ans,dp[N-1][i]);
    cout << ans << endl;
}