#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

bool is_palindrome(string s){
    ll len = s.length();
    rep(i, len/2){
        if(s[i] != s[len-1-i]) return false;
    }
    return true;
}

int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll n;
        cin >> n;
        vector<ll> s(n);
        vector<vector<ll>> grid(n, vector<ll>(n));
        rep(i,n){
            rep(j,n){
                is_palindrome(s)
            }
        }
    }
}