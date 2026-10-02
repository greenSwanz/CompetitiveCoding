#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
const ll p = 998244353;
int main(){
    string s; cin >> s; ll n = s.size();
    vector<ll> A(n,0); vector<ll> B(n,0); vector<ll> C(n,0);
    if (s[0] == 'a' ) A[0]++;
    if (s[0] == 'b' ) B[0]++;
    if (s[0] == 'c' ) C[0]++;
    repp(i,1,n){
        A[i] = A[i-1]; B[i] = B[i-1]; C[i] = C[i-1];
        if(s[i] == 'a'){A[i] = (A[i-1] + (B[i-1] + C[i-1]) % p + 1) % p;}
        if(s[i] == 'b'){B[i] = (B[i-1] + (A[i-1] + C[i-1]) % p + 1) % p;}
        if(s[i] == 'c'){C[i] = (C[i-1] + (B[i-1] + A[i-1]) % p + 1) % p;}
    }
    cout << (A[n-1] + B[n-1] + C[n-1]) % p << endl;
}