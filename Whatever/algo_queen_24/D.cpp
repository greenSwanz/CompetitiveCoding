#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T; cin >> T;
    rep(_,T){
        ll N,X,Y; cin >> N >> X >> Y;
        vector<ll> A(N); rep(i,N) cin >> A[i];
        vector<ll> dp(N); dp[0] = A[0];
        repp(i,1,N){
            dp[i] = A[i];
            rep(j,i){
                dp[i] = min(dp[i], dp[i-(j+1)] + dp[j] + X);
            }
        }
        cout <<  min(A[N-1], dp[N-1] + Y) << endl;
    }
}