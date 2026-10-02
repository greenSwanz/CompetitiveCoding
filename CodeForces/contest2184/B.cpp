#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int n;
    cin >> n;

    rep (i,n){

        int s, m, k;
        cin >> s >> k >> m;

    if (s <= k) {
        if ((s - (m % k)) < 0){
            cout << 0 << endl;
        }
        else {
            cout << (s - (m % k)) << endl;
        }
    }

    else {
        if (((m / k) % 2) == 0) {
            if ((s - (m % k)) < 0) {
                cout << 0 << endl;
            }
            else{
                cout << (s - (m % k)) << endl;
            }
        }
        else {
            if ((k - (m % k)) < 0) {
                cout << 0 << endl;
            }
            else{
                cout << (k - (m % k)) << endl;
            }
        }
    }

    }

    
    return 0;
}