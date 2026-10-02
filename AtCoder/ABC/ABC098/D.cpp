#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<ll> xor_sum(N+1,0); vector<ll> add_sum(N+1,0);
    repp(i,1,N+1) xor_sum[i] = xor_sum[i-1] ^ A[i-1];
    repp(i,1,N+1) add_sum[i] = add_sum[i-1] + A[i-1];
    ll total = 0;
    rep(i,N){
        ll low = i+1; ll high = N; ll best = i+1;
        while(low <= high){
            ll mid = (high + low)/2;
            if((xor_sum[mid] ^ xor_sum[i]) == (add_sum[mid] - add_sum[i])) {
                best = mid;
                low = mid +1;
            }
            else high = mid-1;
        }
        total += best - i;
    }
    cout << total << endl;
}