#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll p = 1000000007;

ll power(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    ll N,M; cin >> N >> M;
    ll cur = M;
    ll total = 0;
    map<ll,ll> pfacts;
    ll x = M;
    for (ll i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            pfacts[i]++;
            x /= i;
        }
    }
    if (x > 1) pfacts[x]++;
    vector<ll> powers;
    for(auto it : pfacts){
        powers.push_back(it.second);
    }
    ll mx = 0;
    for (auto e : powers) mx = max(mx, e);
    ll m = N - 1 + mx;
    vector<ll> f(m+1,1); vector<ll> invf(m+1,1);
    repp(i,1,m+1) f[i] = f[i-1] * i % p;
    invf[m] = power(f[m], p - 2);
    for (ll i = m; i >= 1; i--) invf[i - 1] = invf[i] * i % p;
    ll res = 1;
    rep(i,powers.size()){
        ll num = f[N-1 + powers[i]];
        ll den = invf[powers[i]] * invf[N-1] % p;
        res = res * (num * den % p) % p;
    }
    cout << res << endl;
}