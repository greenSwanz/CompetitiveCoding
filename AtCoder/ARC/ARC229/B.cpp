#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T; cin >> T;
    rep(_,T){
        ll N; cin >> N; vector<ll> A(N); rep(i,N) cin >> A[i];
        bool flag = false;
        repp(i,1,N){ if(A[i] > A[i-1]) {flag = true;} break;}
        if(flag) {cout << -1 << endl; continue;}
        
    }
}