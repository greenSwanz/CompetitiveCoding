#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q; cin >> N >> Q;
    vector<ll> A(N,0);
    ll total = 0;
    set<ll> pos; 
    rep(i,Q){
        ll a,b; cin >> a;
        if(a == 1){
            cin >> b;b--;
            total ^= A[b];
            A[b]++;
            total ^= A[b];
            pos.insert(b);
        } 
        if(a == 2) {
            for(auto it = pos.begin(); it != pos.end();){
                ll i = *it;
                total ^= A[i];
                A[i]--;
                total ^= A[i];
                if(A[i] == 0) it =  pos.erase(it);
                else ++it;
            }
        }
        cout << total << endl;
}
}