#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q; cin >> N >> Q; vector<P> A(N); rep(i,N){cin >> A[i].first; A[i].second = i+1;} sort(A.begin(),A.end());
    rep(_,Q){
        ll K; cin >> K;
        vector<ll> b(K); rep(i,K) cin >> b[i];
        bool found = false; ll index = 0;
        while(!found){
            if(lower_bound(b.begin(),b.end(),A[index].second) == b.end()){
                found = true; break;}
            if(*(lower_bound(b.begin(),b.end(),A[index].second)) == A[index].second) index++;
            else found = true;
        }
        cout << A[index].first << endl;
    }
}