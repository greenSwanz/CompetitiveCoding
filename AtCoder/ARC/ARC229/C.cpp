#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T; cin >> T;
    rep(_,T){
        ll N; cin >> N; vector<ll> A(N); rep(i,N) cin >> A[i];
        vector<ll> odd,even;
        rep(i,N){
            if(A[i] % 2 == 0) even.push_back(A[i]);
            else odd.push_back(A[i]);
        }
        ll o = odd.size(), e = even.size();
        if(o >= 1) {sort(odd.begin(),odd.end());}
        if(e >= 1) {sort(even.begin(),even.end());}
        ll total = 0;
        rep(i,N) total += 2 * A[i];
        if(N == 1){ cout << 0 << endl; continue; }
        ll temp = 0;
        if(o >= 2) temp = max(temp, odd[o-1]  + odd[o-2]  + 2*min(e, o-1));
        if(e >= 2) temp = max(temp, even[e-1] + even[e-2] + 2*min(o, e-1));
        if(o && e) temp = max(temp, odd[o-1]  + even[e-1] + 2*min(o, e) - 1);
        total -= temp;
        cout << total / 2 << endl;
    }
}