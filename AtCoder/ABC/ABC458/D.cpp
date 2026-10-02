#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll X,Q; cin >> X >> Q;
    set<P> ints; ints.insert({X,0}); P temp = {X,0}; ll counter = 0;
    rep(i,Q) {
        ll A,B; cin >> A >> B;
        ints.insert({A,++counter}); ints.insert({B,++counter}); 
        if(A < temp.first && B < temp.first) { auto it = ints.find(temp); --it; temp = *it; }
        if(A > temp.first && B > temp.first) { auto it = ints.find(temp); ++it; temp = *it; }
        cout << temp.first << endl;
    }
}