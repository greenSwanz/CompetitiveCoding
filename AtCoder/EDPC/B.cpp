#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int n,k;
    cin >> n >> k;

    int h[n];
    rep(i,n) {
        cin >> h[i];
    }

    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    if(k<n){
    repp(i,2,k){
        dp[i] = (abs(h[i] - h[i-1]) + dp[i-1]);
        rep(j,(i+1)){
            if((abs(h[i] - h[i-j]) + dp[i-j]) < dp[i]){
                dp[i] = (abs(h[i] - h[i-j]) + dp[i-j]);
            }
        }

    }

    repp(i,k,n){
        dp[i] = (abs(h[i] - h[i-1]) + dp[i-1]);
        rep(j,(k+1)){
            if((abs(h[i] - h[i-j]) + dp[i-j]) < dp[i]){
                dp[i] = (abs(h[i] - h[i-j]) + dp[i-j]);
            }        
        }
    }
    }

    else{
        repp(i,2,n){
        dp[i] = (abs(h[i] - h[i-1]) + dp[i-1]);
        rep(j,i){
            if((abs(h[i] - h[i-j]) + dp[i-j]) < dp[i]){
                dp[i] = (abs(h[i] - h[i-j]) + dp[i-j]);
            }
        }

    }
    }
    
    cout << dp[n-1] << endl;
    return 0;
}