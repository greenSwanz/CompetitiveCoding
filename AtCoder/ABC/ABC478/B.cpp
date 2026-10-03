#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N, V; cin >> N >> V; vector<ll> hap(N,0);
    rep(i,N) cin >> hap[i];
    ll m = hap[0] + hap[1] + hap[2];
    rep(i,N){
        rep(j,N){
            rep(k,N){
                if(i+j+k + 3 <= V && (i!=j) && (j!=k) && (i!=k)){
                    m = max(m , hap[i] + hap[j] + hap[k]);
                }
            }
        }
    }
    cout << m << endl;
}