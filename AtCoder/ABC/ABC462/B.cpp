#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<set<ll>> A(N);
    //rep(i,N){ A[i] = 0;}
    ll K;
    rep(i,N){
        cin >> K;
        rep(i,K){
            ll temp;
            cin >> temp;
            A[temp].insert(i+1);
        }
    }

    repp(i,1,N){
        for (ll s : A[i]) {
        cout << s;
    }
    cout << endl;
    }
    
}