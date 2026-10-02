#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

ll fact(ll n) {
    if (n > 1) {
        return n * fact(n - 1);
    } else {
        return 1;
    }
}

int main(){
    ll N,M;
    cin >> N >> M;

    ll A[N+1];
    rep(i,(N+1)){
        A[i] = 0;
    }
    ll temp;
    ll temp2;
    rep(i,M){
        cin >> temp >> temp2;
        A[temp] += 1;
        A[temp2] += 1;
    }

    ll semi;
    repp(i,1,N+1){
        semi = (N - A[i] - 1);
        if (semi > 2){
            cout << ((semi * (semi -1) * (semi-2))/(6)) << endl;
        }
        else{
            cout << 0 << endl;
        }
    }

}