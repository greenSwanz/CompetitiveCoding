#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; vector<P> pairs;
    rep(i,N-1){
        ll t1,t2; cin >> t1 >> t2;
        pairs.push_back(P(min(t1,t2), max(t1,t2)));
    }
    ll total =0; 
    rep(i,N-1){total -= (pairs[i].first * (N+1-pairs[i].second));}
    ll j = N-1; ll diff = -2;
    repp(i,1,N+1){total += ((N+1-i) * i);}
    cout << total << endl;
}