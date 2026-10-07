#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

int main(){
    ll t; cin >> t;
    rep(_,t){
        ll n; cin >> n; vector<ll> a(n),b(n); vector<P> c(n); vector<P> d(n);
        rep(i,n){
            cin >> a[i] >> b[i];
            c[i] = {a[i],b[i]};
        }
        sort(c.begin(), c.end());
        ll total = 0; ordered_set<ll> bs;
        rep(i,n){
            total += bs.size() - bs.order_of_key(c[i].second);
            bs.insert(c[i].second);
        }
        cout << total << endl;
    }
}