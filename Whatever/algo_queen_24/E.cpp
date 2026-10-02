#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T; cin >> T;
    rep(_,T){
        ll N, Q; cin >> N >> Q; ll A[N]; ll q[Q];
        vector<ll> dp(N,0);
        rep(i,N) cin >> A[i]; 
        rep(i,Q) cin >> q[i];
        ll left = -1;
        if(A[0] == 1) { dp[0] = 1; left = 0; }
        repp(i,1,N){
            if(A[i] == 1){
                if(left == -1){ left = i; dp[i] = dp[i-1] + 1;}
                else {dp[i] = dp[i-1] + (i-left +1);}
            }
            else {left = -1; dp[i] = dp[i-1];}
        }
        rep(i,Q){
            cout << dp[q[i] -1] << endl;
        }
}
}