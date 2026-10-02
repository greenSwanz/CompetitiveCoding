#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q; cin >> N >> Q; vector<bool> flag(N+1,false);
    vector<ll> P(N); rep(i,N) {cin >> P[i]; }
    rep(_,Q){
        ll a; cin >> a;
        P.push_back(a);
    }
    vector<ll> ans;
    repp(i,1,P.size() + 1){
        if(!flag[P[P.size()-i]])
        ans.push_back(P[P.size()-i]); flag[P[P.size()-i]] = true;
    }
    reverse(ans.begin(),ans.end());
    rep(i,N) cout << ans[i] << " "; cout << endl;

}