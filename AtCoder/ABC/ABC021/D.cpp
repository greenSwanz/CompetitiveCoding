#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll p = 1000000007;

ll fact(ll num){
    ll f = 1;
    repp(i,2,num+1) f = (f * i) % p;
    return f;
}

ll power(ll a, ll b, ll p){
    ll res = 1;
    a %= p;
    while (b > 0){
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    ll n,k;
    cin >> n >> k;
    ll N_fact = fact(n+k-1);
    ll k_fact = fact(k);
    ll Nk_fact = fact(n-1);
    ll D = (k_fact * Nk_fact) % p;
    ll r = ((N_fact * power(D, p-2, p)) % p);
    cout << r << endl;
    return 0;    
}   