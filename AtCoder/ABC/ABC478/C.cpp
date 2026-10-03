#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K; cin >> N >> K; vector<ll> A(N); vector<ll> B;
    rep(i,N) {cin >> A[i];} B = A;
    sort(B.begin(), B.end()); ll l=-1,r=-1;
    rep(i,N){
        if(A[i] != B[i]) {if(l<0) l = i; r = i;}
    }
    cout << ((r-l+1 > K) ? "No" : "Yes") << endl;
}