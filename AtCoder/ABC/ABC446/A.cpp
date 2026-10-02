#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    string of = "Of";
    cout << (of + char(int(S[0]) + 32) + S.substr(1,S.length() -1)) << endl;
}