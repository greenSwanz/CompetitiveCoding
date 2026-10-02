#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll D,M; cin >> M >> D;
    string S; cin >> S;
    ll left,right;
    vector<bool> guarded(M,false);
    rep(i,M){
        if(S[i] == 'G'){
            left = max(i-D,0LL); right = min(M-1,i+D);
            repp(j,left,right+1) guarded[j] = true;
        }
    }
    ll ung = 0;
    rep(i,M){
        if(!(guarded[i])) ung++;
    }
    cout << ung << endl;

}