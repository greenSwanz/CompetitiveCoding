#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; cin >> N >> K; map<ll,ll> m; ll ma = 0;
    rep(i,N) {ll temp; cin >> temp; m[temp]++; ma = max(ma,m[temp]);} ll total = 0;
    for(auto i : m) {if(i.second + 1 >= ma) total++;}
    cout << total << endl;
}