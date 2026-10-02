#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;

    ll A[N];
    ll B[N];
    ll C[N];


    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }
    rep(i,N){
        cin >> C[i];
    }

    sort(A,A+N);
    sort(B,B+N);
    sort(C,C+N);

    ll counter = 0;

    ll sums[N];
    rep(i,N){
        auto temp2 = upper_bound(C, C+N, B[i]) - C;
            sums[i] = (N- temp2);
    }
        repp(i,1,N+1){
        sums[N-i-1] += sums[N-i];
    }
    rep(i,N){
        auto temp = upper_bound(B, B+N, A[i]) - B;
        if(temp < N){
            counter += sums[temp];
        }                
    }
    cout << counter << endl;
        
    
}