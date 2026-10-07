#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t; cin >> t;
    rep(_,t){
        ll n; cin >> n;
        vector<ll> a(n);
        map<ll,vector<ll>> m;
        rep(i,n){
            cin >> a[i];
        }
        vector<ll> triad(n);
        repp(i,4,n){
            triad[i] = a[i-4] + a[i-2] - a[i]; m[triad[i]].push_back(i);
        }
        ll total = 0;
        for(auto &i : m){
            for(auto j : i.second){
                auto it = lower_bound(i.second.begin(), i.second.end(), j+2);
                auto it2 = lower_bound(i.second.begin(), i.second.end(), j+4);
                total += i.second.end() - lower_bound(i.second.begin(), i.second.end(), j) - 1
                       - (it != i.second.end() && *it == j+2)
                       - (it2 != i.second.end() && *it2 == j+4);
            }
        }
        cout << total << endl;
    }
}
