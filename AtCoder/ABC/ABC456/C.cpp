#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
const ll p = 998244353;
int main(){
    string s; cin >> s;
    ll temp = 1; ll total = 0;
    repp(i,1,s.size()){
        if(s[i] == s[i-1]){ total = (total + (((temp) * (temp+1))/2)) % p; temp = 1;}
        else { temp++; }
    }
    total = (total + (((temp) * (temp+1))/2)) % p;
    cout << total << endl;
}