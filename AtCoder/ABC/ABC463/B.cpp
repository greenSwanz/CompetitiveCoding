#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    char X;
    char temp;
    cin >> N >> X;
    rep (i,N){
        rep(j,5){
            cin >> temp;
            if (j == X-'A' && temp == 'o'){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}