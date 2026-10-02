#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll X,Y,L,R,A,B;
    cin >> X >> Y >> L >> R >> A >> B;
    ll x = max(0LL, min(B,R) - max(A,L));
    ll y = (B-A) - x;
    cout << (x*X + y*Y) << endl;
}