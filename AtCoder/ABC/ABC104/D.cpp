#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
const ll p = 1000000007;
int main(){
    string s; cin >> s; ll n = s.size();
    vector<ll> a(n+1,0), b(n+1,0), c(n+1,0), t(n+1,1);
    repp(i,1,n+1){
        a[i] = a[i-1]; b[i] = b[i-1]; c[i] = c[i-1]; t[i] = t[i-1];
        if(s[i-1] == '?'){
            t[i] = (t[i-1] * 3) % p;
            a[i] = ((a[i] * 3) % p + t[i-1]) % p;
            b[i] = ((b[i] * 3)%p + a[i-1]) % p;
            c[i] = ((c[i] * 3)% p + b[i-1]) % p;
        }
        if(s[i-1] == 'A') a[i] = (a[i-1] + t[i-1]) % p;
        if(s[i-1] == 'B') b[i] = (b[i-1] + a[i-1]) % p;
        if(s[i-1] == 'C') c[i] = (c[i-1] + b[i-1]) % p;
    }
    cout << c[n] % p << endl;
}