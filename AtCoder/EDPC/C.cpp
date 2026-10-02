#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;

    ll A[N];
    ll B[N];
    ll C[N];

    rep(i,N){
        cin >> A[i] >> B[i] >> C[i];
    }

    int dp[N][3];

    dp[0][0] = A[0];
    dp[0][1] = B[0];
    dp[0][2] = C[0];

    repp(i,1,N){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + A[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + B[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + C[i];
    }

    cout << max (dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << endl;


}