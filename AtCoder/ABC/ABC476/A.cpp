#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S; cin >> S;
    if(S[S.size()-1] == 'e') {cout << S << 'r' << endl; return 0;}
    cout << S << "er" << endl;
}