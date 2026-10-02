#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll p = 998244353;
 
ll power(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = res * a % p;
        a = a * a % p;
        b >>=1;
    }
    return res;
}
int main(){
    ll N; cin >> N; ll A[N];
    rep(i,N) cin >> A[i];
    vector<ll> P(N+1,0), Q(N+1,0);
    repp(i,1,N+1){
        P[i] = (P[i-1] + power(i, p-2)) % p;
        Q[i] = (Q[i-1] + P[i]) % p;
    }
    ll f = 0;
    rep(i,N){
        ll temp = ((Q[N] - Q[i] - Q[N-1-i]) % p + p) % p;
        f = (f + (A[i] % p + p) % p * temp) % p;
    }
    cout << f % p << endl;
}