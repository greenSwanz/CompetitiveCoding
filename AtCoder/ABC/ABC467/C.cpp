#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M; cin >> N >> M;
    ll A[N]; ll B[N-1];
    rep(i,N) cin >> A[i]; rep(i,N-1) cin >> B[i];ll total = 0;
    ll f = 0, k = 0;
    repp(i,1,N){
        ll d = ((A[i-1] + A[i]) % M != B[i-1]) ? 1 : 0;
        f ^= d; k += f;
    }
    cout << min(k, N - k) << endl;
}


    
