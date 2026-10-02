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
        int n;
        cin >> n;

        int modFour = n % 4;

        if (n < 4) {
            cout << modFour << endl;
        }
        else {
            cout << (modFour % 2) << endl;
        }
    }

    return 0;
}