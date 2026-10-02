#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
auto ev = [](ll lo, ll hi){
    if(lo > hi) return 0LL;
    return (hi >> 1) - ((lo - 1) >> 1);
};
int main(){
    ll L,R,D,U; cin >> L >> R >> D >> U; ll b=0;
    repp(i,L,R+1){
        ll m = abs(i);
        ll lb = max(D, -m); ll ub = min(U, m);
        if(m % 2 == 0 && lb <= ub) b += (ub - lb + 1);
        ll ltail = ev(D, min(U,-m-1));
        ll utail = ev(max(D,m+1), U);
        b+= utail + ltail;
    }
    
    cout << b << endl;
}