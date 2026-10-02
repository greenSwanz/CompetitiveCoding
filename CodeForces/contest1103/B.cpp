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
        ll N,K;
        cin >> N >> K;
        string c;
        cin >> c;
        vector<ll> cnt(K, 0);
        bool ok = true;
        rep(i,N){
            if(c[i] == '1'){
                cnt[i % K]++;
            }
        }
        rep(r,K){
            if(cnt[r] % 2 != 0) ok = false;
        }
        if(!ok) {
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
}