#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int P,Q,X,Y;
    cin >> P >> Q;
    cin >> X >> Y;

    if(((X-P) < 100) && ((Y-Q) < 100) && ((X-P) >= 0) && ((Y-Q) >= 0)) {
        cout << "Yes" << endl;
    }

    else{
        cout << "No" << endl;
    }

    return 0;
}