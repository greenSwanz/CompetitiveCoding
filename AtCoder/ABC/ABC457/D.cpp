#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; cin >> N >> K; vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll lo = 1; ll hi = 2000000000000000000; ll mid;
    while (lo<hi)
    {
        mid = lo + (hi - lo +1) / 2;
        ll total = 0;
        bool flag = false;
        rep(i,N){
            if(mid > A[i]){
                ll temp = ((mid - A[i]) % (i+1) == 0) ? ((mid - A[i]) / (i+1)) : ((mid - A[i]) / (i+1)) +1;
                if(temp > K) {flag = true; break;}
                total += temp; if(total > K) {flag = true; break;}
            }
        }
        if(flag || total > K) hi = mid-1;
        else lo = mid;
    }
    cout << lo << endl;
}