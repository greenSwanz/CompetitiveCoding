#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; cin >> N >> K;
    vector<ll> A(N); map<ll,ll> m; set<ll> s;
    rep(i,N) {cin >> A[i]; m[A[i]]++; s.insert(A[i]);} vector<ll> v;
    for(auto i  : s) v.push_back(i * m[i]);
    sort(A.begin(), A.end());
    sort(v.begin(),v.end());
    ll total = 0; ll p = max(0LL,(ll) s.size()-K);
    rep(i,p) {total += v[i];}
    cout << total << endl;
}