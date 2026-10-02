#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
const ll p = 998244353;

ll power(ll a,ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = res * a % p;
        a = a * a %p;
        b >>= 1;
    }
    return res;
}

vector<ll> f, invf;
ll ncr(ll n, ll r){
    if(r < 0 || n < 0 || r > n) return 0;
    return f[n] * invf[r] % p * invf[n-r] % p;
}

int main(){
    ll N,K; cin >> N >> K;
    f.assign(N+1,1); invf.assign(N+1,1);
    repp(i,1,N+1) f[i] = (i * f[i-1]) % p;
    invf[N] = power(f[N], p-2);
    for(ll i = N; i >= 1; --i) invf[i-1] = (invf[i] * i) % p;

    ll s1 = 0, s2 = 0;
    rep(i,N){
        ll x; cin >> x; x %= p;
        s1 = (s1 + x) % p;
        s2 = (s2 + x * x) % p;
    }
    ll a = ncr(N-1, K-1);
    ll b = ncr(N-2, K-2);
    ll ans = (s2 % p * a + (s1 * s1 % p - s2 + p) % p * b) % p;
    cout << ans << endl;
}