#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    string out = "";
    cin >> S;
    rep(i,S.length()){
        if(S[i] >= 48 && S[i] <= 57 ){
            out += S[i];
        }
    }
    cout << out << endl;
}