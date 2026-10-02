#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int t;
    cin >> t;

    rep (i,t){
    ll n,k;
    cin >> n >> k;
    ll temp;
    if (k > 3){
        temp = ( n - (-1 * (1-(pow(2,(k-1))))) + ((-1 * (1-(pow(3,(k-3)))))/2));
    }
    else{
        temp = ( n - (-1 * (1-(pow(2,(k-1))))));
    }
    if ((temp) < 0){
        cout << 0 << endl;
    }
    else{
        cout << (temp - 1) << endl;
    }
}
return 0;
}