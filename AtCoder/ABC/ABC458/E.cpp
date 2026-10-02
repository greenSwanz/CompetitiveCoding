#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll p = 998244353;
vector<ll> f, invf;

ll ncr(ll n, ll r){
    if(n < 0 || n < r || r < 0) return 0;
    return f[n] * (invf[n-r] * invf[r] % p) % p;
}

ll power(ll a, ll b, ll p){
    ll res = 1;
    a %= p;
    while(b>0){
        if(b&1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    ll X,Y,Z; cin >> X >> Y >> Z;
    ll N = X + Y + Z; f.resize(N+1); invf.resize(N+1); //initialise the highest power
    f[0] = 1; 
    repp(i,1,N+1) f[i] = f[i-1] * i % p; //fill the factorials
    invf[N] = power(f[N], p-2, p); // fermats little theorem once at the top to find inverse fact(N)
    for(ll i = N; i > 0; --i)
        invf[i-1] = invf[i] * i % p; //compute inverse factorial going down 

    ll total = 0;
    ll num; ll den;
    repp(i,2,X+1) {
        total += ncr(X-1,i-1) * (ncr(Z-1,i-2) * ncr(X+Y+Z - (2*i-2),(X+Z)) % p) % p;
    }
    repp(i,2,Z+1) {
        total += ncr(Z-1,i-1) * (ncr(X-1,i-2) * ncr(X+Y+Z - (2*i-2),(X+Z)) % p) % p;
    }
    repp(i,1,min(X,Z)+1) {
        total += 2 * (ncr(X-1,i-1) * (ncr(Z-1,i-1) * ncr(X+Y+Z - (2*i-1),(X+Z)) % p) % p) % p;
    }
    cout << total % p << endl;
}