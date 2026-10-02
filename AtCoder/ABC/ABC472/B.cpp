#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; vector<ll> L(N);
    rep(i,N) cin >> L[i];
    repp(i,1,N) {L[i] = L[i] + L[i-1];}
    auto it = lower_bound(L.begin(),L.end(),L[N-1]/2); ll temp = abs(*it - (L[N-1] - *it));
    it--; ll temp2 = abs(*it - (L[N-1] - *it));
    cout << min(temp,temp2)  << endl;
    
}