#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S; cin >> S; ll len; len = S.length();
    vector<ll> cs; ll total = 0;
    rep(i,len) { if(S[i] == 'C') cs.push_back(i); }
    rep(i,cs.size()) total+= max(0LL, min(cs[i], len-cs[i]-1));
    total+= cs.size();
    cout << total << endl;
}