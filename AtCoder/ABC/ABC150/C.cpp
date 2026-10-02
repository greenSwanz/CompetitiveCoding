#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<ll> P(N),Q(N),V(N);
    rep(i,N){
        cin >> P[i];
        V[i] = i+1;
    }
    rep(i,N){
        cin >> Q[i];
    }

    ll p = 0;
    ll q = 0;

    bool pflag = false;
    bool qflag = false;
    do{
        if(V == P) pflag = true;
        if(V == Q) qflag = true;
        if(!(pflag)) p++;
        if(!(qflag)) q++;
    }
    while(next_permutation(V.begin(), V.end()));

    cout << abs(p - q) << endl;
    return 0;
}