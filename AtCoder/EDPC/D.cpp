#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N, W;
    cin >> N >> W;

    P A[N];
    rep(i,N){
        cin >> A[i].first >> A[i].second;
    }

    ll dp[N][W+1];

    rep(i,(W+1)){
        if (A[0].first <= i){
            dp[0][i] = A[0].second;
        }
        else{
            dp[0][i] = 0;
        }
        
    }

    repp(i,1,N){
        rep(j,(W+1)){
            if ((A[i].first <= j)){
                dp[i][j] = max((dp[i-1][j- A[i].first] + A[i].second), dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];

            }
        }
    }

    cout << dp[N-1][W] << endl;



}