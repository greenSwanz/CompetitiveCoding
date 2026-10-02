#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S; cin >> S;
    ll total = 0;
    rep(i,S.size()){
        ll range = min( ll (S.size() - (i+1)), i);
        ll difc = 0;
        rep(j, range+1){
            if(S[i-j] != S[i+j]) difc++;
            if(difc <= 1) total++;
        }
    }
    rep(i,S.size()-1){
        ll a = i; ll b = i+1;
        ll range = min( ll (S.size() - (i+2)), i);
        ll difc = 0;
        rep(j, range+1){
            if(S[a-j] != S[b+j]) difc++;
            if(difc <= 1) total++;
        }
    }
    cout << total << endl;
}