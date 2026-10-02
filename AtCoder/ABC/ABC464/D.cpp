#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,c,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll N;
        string S;
        cin >> N >> S;
        vector<ll> X(N);
        vector<ll> Y(N-1);
        rep(i,N) cin >> X[i];
        rep(i,N-1) cin >> Y[i];

        vector<ll> dpS(N), dpR(N);
        dpS[0] = (S[0] == 'S') ? 0 : -X[0];
        dpR[0] = (S[0] == 'R') ? 0 : -X[0];

        repp(i,1,N){
            ll costS = (S[i] == 'S') ? 0 : -X[i];
            ll costR = (S[i] == 'R') ? 0 : -X[i];
            dpS[i] = costS + max(dpS[i-1], dpR[i-1] + Y[i-1]);
            dpR[i] = costR + max(dpS[i-1], dpR[i-1]);
        }

        cout << max(dpS[N-1], dpR[N-1]) << endl;
    }
}