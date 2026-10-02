#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    map<ll,ll> m; ll N; cin >> N; ll A[N]; 
    rep(i,N) {cin >> A[i];  m[A[i]] = max(m[A[i] -1] +1,m[A[i]]); }
    ll ans = 1; for(auto i : m) ans = max(ans,i.second);
    cout << ans << endl;
}