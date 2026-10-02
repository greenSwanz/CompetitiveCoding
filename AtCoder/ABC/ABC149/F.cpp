#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll p = 1000000007;

vector<pair<ll,set<ll>>> tree;
vector<ll> sz;                

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

void dfs(ll v, ll parent){
    sz[v] = 1;
    for(ll child : tree[v].second) {
        if (child == parent) continue;
        dfs(child,v);
        sz[v] += sz[child];
    }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> vertices(N);
    tree.resize(N);
    sz.resize(N);
    rep(i, N-1){
        ll a, b; cin >> a >> b;
        tree[a-1].second.insert(b-1);
        tree[b-1].second.insert(a-1);
    }
    dfs(0, -1);
    ll inv2 = power(2,p-2,p);
    ll res = 0;
    ll all_white = power(inv2,N-1,p);
    rep(i,N){
        ll sum_k_side_black = 0;
        ll d = tree[i].second.size();
        for(ll it : tree[i].second){
            ll c = (sz[it] > sz[i]) ? (N - sz[i]) : sz[it];
            sum_k_side_black = (sum_k_side_black + (( (1 - power(inv2,c,p)) % p + p) % p) * (all_white * power(2,c,p) % p) ) % p;
        }
        res = (res + inv2 * (((1 - all_white - sum_k_side_black) % p + p) % p)) % p;
    } 
    cout << res << endl;
}