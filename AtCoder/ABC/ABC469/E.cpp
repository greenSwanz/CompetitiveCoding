#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; cin >> N >> K;
    string S; cin >> S; vector<ll> sums(N+1,0);
    repp(i,1,N+1){
        sums[i] = sums[i-1];
        if(S[i-1] == 'o') sums[i]++;
    }
    double left = 0; double right = 1.0;
    while (left<right)
    {
        repp(i,1,N+1){
        ll temp = lower_bound(sums.begin(), sums.end(),sums[i] + K) - sums.begin();
        m = max(m,(double) K/(temp - i));
        }
    }
}