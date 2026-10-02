#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; cin >> N >> K; K--;
    vector<vector<ll>> A(N,vector<ll>()); vector<ll> L(N);
    rep(i,N){
        cin >> L[i];
        rep(j,L[i]){
            ll temp; cin >> temp;
            A[i].push_back(temp);
        }
    }
    vector<ll> C(N); rep(i,N) cin >> C[i];
    vector<ll> cumsum(N+1,0);
    rep(i,N){
        cumsum[i+1] = cumsum[i] + C[i] * L[i];
    }
    auto it = upper_bound(cumsum.begin(), cumsum.end(), K) - cumsum.begin();
    ll order = K - cumsum[it-1]; 
    cout << A[it-1][order % (L[it-1])] << endl;
}
