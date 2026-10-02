#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    ll e,w;
    e = 0;
    w = 0;
    rep(i,S.length()){
        if(S[i] == 'E') e++;
        else w++;
    }
    if(e > w){
        cout << "East" << endl;
        return 0;
    }
    cout << "West" << endl;
}