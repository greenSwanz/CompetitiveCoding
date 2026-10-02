#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

map<ll,ll> sum_ci; map<ll,ll> sum_di; map<ll,ll> ci; map<ll,ll> di;
map<ll,vector<ll>> parents;

ll dfs_c(ll node){
    for(ll it : parents[node]){
        sum_ci[node]+=dfs_c(it);
    }
    return sum_ci[node];
}

ll dfs_d(ll node){
    for(ll it : parents[node]){
        sum_di[node]+=dfs_d(it);
    }
    return sum_di[node];
}

const ll p = 998244353;

ll fact(ll num){
    ll f = 1;
    repp(i,2,num+1) f = (f * i) % p;
    return f;
}
ll fact(ll n, ll k){
    ll f = 1;
    ll nmod = n % p;
    rep(t,k){
        ll factor = ((nmod - t) % p + p) % p;
        f = f * factor % p;
    }
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
    ll N;
    cin >> N;
    rep(i,N-1){
        ll temp;
        cin >> temp;
        parents[temp].push_back(i+2);
    }
    rep(i,N){cin >> ci[i+1]; sum_ci[i+1] = ci[i+1];}
    rep(i,N){cin >> di[i+1]; sum_di[i+1] = di[i+1];}
    dfs_c(1); dfs_d(1);
    ll answer = 1;
    rep(i,N){
        ll y = (sum_ci[i+1] - sum_di[i+1] + di[i+1]);
        if(y < di[i+1]){ answer = 0; break; }
        ll num = fact(y, di[i+1]);
        ll temp = num % p * power(fact(di[i+1]), p-2, p) % p;
        answer = answer * temp % p;
    }
    cout << answer << endl;
}