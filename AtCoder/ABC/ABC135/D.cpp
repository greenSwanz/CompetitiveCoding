#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll p = 1000000007;

int main() {
    string S; cin >> S; ll n = S.size();
    vector<vector<ll>> dp(n+1, vector<ll>(13, 0));
    dp[0][0] = 1;
    rep(i,n) {
        ll c;
        if(S[i] == '?') c = -1;
        else c = S[i] - '0';
        rep(j,10){
            if(c != -1 && c != j) continue;
            rep(k,13) dp[i+1][(10*k + j ) % 13] = (dp[i+1][(10*k + j ) % 13] + dp[i][k]) % p;
        }
        rep(j,10) dp[i+1][j] %= p;
    }
    cout << dp[n][5] % p << endl;
}