#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; vector<ll> A(N);
    char temp;
    rep(i,N){
        cin >> temp;
        if(temp == 'o'){
            A[i] = 1;
        }
    }
    ll total = 0;
    repp(i,1,N-1){
        if(A[i] == 0 && A[i-1] == 0 && A[i+1] == 0) total++;
    }
    if (A[0] == 0 && A[1] == 0) total++;
    if (N>1 && A[N-1] == 0 && A[N-1-1] == 0) total++;
    cout << total << endl;
}