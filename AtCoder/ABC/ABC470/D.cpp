#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q; cin >> N >> Q;
    vector<ll>p1(N+1); vector<ll>p2(N+1); vector<ll> P(N+1); ll pointer = 2;
    repp(i,1,N+1){ cin >> p2[i]; p1[p2[i]] = i; }
    P = p2;
    rep(i,Q){
        ll q,x,y;
        cin >> q;
        if(q == 1){
            cin >> x >> y;
            if(pointer == 2) {
                swap(p2[x], p2[y]);
                swap(p1[p2[x]],p1[p2[y]]);
            }
            else{
                swap(p1[x], p1[y]);
                swap(p2[p1[x]],p2[p1[y]]);
            }
        }
        else{
            if(pointer == 2) pointer = 1;
            else pointer = 2;
        }
    }
    repp(i,1,N+1){
        if(pointer == 1) cout << p1[i] << " ";
        else cout << p2[i] << " ";
    }
}