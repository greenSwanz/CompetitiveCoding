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
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        cin >> B[i];
    }
    repp(i,1,N){
        if(!(A[B[i]-1] == i+1)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}