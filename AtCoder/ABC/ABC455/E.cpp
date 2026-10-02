#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;
    string S; cin >> S;
    vector<ll> A(N+1,0); vector<ll> B(N+1,0); vector<ll> C(N+1,0);
    repp(i,1,N+1){
        A[i]  = A[i-1] + (S[i-1] == 'A')  ? 1 : 0;
        B[i]  = B[i-1] + (S[i-1] == 'B')  ? 1 : 0;
        C[i]  = C[i-1] + (S[i-1] == 'C')  ? 1 : 0;
    }
    ll total = 0;
    repp(i,1,N+1){
        total = total * 2 + (A[i] != B[i] != C[i]) ? 1 : 0;
    }
}