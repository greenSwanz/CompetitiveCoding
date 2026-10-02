#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    ll A,B,X,Y;
    rep(_,T){
        ll total = 0;
        cin >> A >> B >> X >> Y;
        ll x = llabs(X), y = llabs(Y), m = min(x,y), d = max(x,y) - min(x,y);
        if(3*A < B){
            total += 2 * (m * A);
            total += d * A;
            total += 2 * (x >= y ? d/2 : (d+1)/2) * A;
        }
        else if(A < B){
            total += 2 * (m * A);
            total += (d / 2) * A;
            total += (d / 2) * B;
            if (d & 1) total += (x >= y ? A : B);
        }
        else if(3*B < A){
            total += 2 * (m * B);
            total += d * B;
            total += 2 * (y >= x ? d/2 : (d+1)/2) * B;
        }
        else {
            total += 2 * (m * B);
            total += (d / 2) * B;
            total += (d / 2) * A;
            if (d & 1) total += (y >= x ? B : A);
        }
        cout << total << endl;
    }
}