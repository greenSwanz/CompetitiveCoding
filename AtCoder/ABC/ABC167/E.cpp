#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll p = 998244353;
vector<ll> f,invf;

ll ncr(ll n, ll r){
    if(n < 0 || n < r || r < 0) return 0;
    return f[n] * (invf[n-r] * invf[r] % p) % p;
}

ll power(ll a, ll b){
    ll res = 1;
    a %= p;
    while(b > 0){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    ll N,M,K; cin >> N >> M >> K; ll total = 0;
    ll mm = max(M,N);
    f.resize(mm+1); invf.resize(mm+1); f[0] = 1;
    repp(i,1,mm+1) f[i] = f[i-1] * i % p;
    invf[mm] = power(f[mm],p-2);
    rep(i,mm) invf[mm-i-1] = invf[mm-i] * (mm-i) % p;
    repp(i,N-K,N+1){
        total = (total + (ncr(N-1,i-1) * (M * (power(M-1,i-1) % p) % p) %p) %p) %p; 
        cout << total << endl;
    } 
    cout << (total % p) << endl;
}