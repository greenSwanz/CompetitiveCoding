#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll N;
        cin >> N;
        vector<ll> h(N);
        rep(i,N){
            cin >> h[i];
        }

        sort(h.begin(), h.end());
        cout << (h[N-1] - h[0] +1) << endl;
    }
}