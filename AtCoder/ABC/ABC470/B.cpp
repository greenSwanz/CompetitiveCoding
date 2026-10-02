#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;
    ll c[N]; map<ll,ll> m;
    rep(i,N){
        cin >> c[i];
        m[c[i]]++;
    }
    vector<ll> v;
    for(P i : m){
        v.push_back(i.second);
    }
    sort(v.begin(),v.end());
    cout <<( N - v[v.size()-1]) << endl;

}