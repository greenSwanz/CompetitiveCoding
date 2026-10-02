#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll k;
        cin >> k;
        ll two_count = 0; ll three_count = 0;
        rep(i,k){
            ll temp;
            cin >> temp;
            if (temp == 2) two_count++;
            if (temp >= 3) three_count++;
        }
        if (two_count >= 2 || three_count >= 1) {
            cout << "YES" << endl; continue;
        }
        cout << "NO" << endl;
    }
}