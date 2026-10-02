#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int n;
    cin >> n;

    int h[n];
    rep(i,n) {
        cin >> h[i];
    }

    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    repp(i,2,n){
        dp[i] = min((abs(h[i] - h[i-2]) + dp[i-2]), (abs(h[i] - h[i-1]) + dp[i-1]));
    }
    cout << dp[n-1] << endl;
    return 0;
}