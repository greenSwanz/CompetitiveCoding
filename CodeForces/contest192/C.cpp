#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll n,k;
        cin >> n >> k;
        vector<ll> a(n);
        rep(i,n) cin >> a[i];
        vector<ll> groups;
        rep(i,n){
            if(i==0 || a[i]!=a[i-1]) groups.push_back(1);
            else groups.back()++;
        }
        ll m = groups.size();
        sort(groups.begin(), groups.end());

        ll answer = 0;
        cout << answer << endl;
    }
}