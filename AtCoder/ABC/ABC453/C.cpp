#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;
    ll L[N]; rep(i,N) {cin >> L[i]; L[i] *= 2;}
    ll best = 0;
    for(ll mask = 0; mask < (1<<N); mask++){
        ll c = 0; ll x = 1;
        rep(i,N){
            if((mask >> i) & 1) {if ((x+L[i] > 0 && x < 0) || (x+L[i] < 0 && x > 0) ) {c++;} x = x + L[i];}
            else {if ((x-L[i] > 0 && x < 0) || (x-L[i] < 0 && x > 0) ) {c++;} x = x - L[i];}
        }
        best = max(best,c);
    }
    //long double dp[N+1]; dp[0] = 0.5;
    /*repp(i,1,N+1){
        dp[i] = (fabsl(dp[i-1] - L[i-1]) > fabsl(dp[i-1] + L[i-1])) ? (dp[i-1] + L[i-1]) : (dp[i-1] - L[i-1]);
    }
    long double total = 0;
    repp(i,1,N+1){
        if((dp[i] > 0 && dp[i-1] < 0) || (dp[i] < 0 && dp[i-1] > 0)) total++;
    }*/
    cout << best << endl;
}