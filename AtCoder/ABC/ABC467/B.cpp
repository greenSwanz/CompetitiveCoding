#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll total = 10000;
    ll Y = 10000;
    ll N; cin >> N;
    ll A,B; string S;
    rep(i,N){
        cin >> A >> B >> S;
        if (S == "take") {
            total -= A;
        }
        else{
            total -= B;
        }
        Y -= A;

    }
    cout << Y - total << endl;
}