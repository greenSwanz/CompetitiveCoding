#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll x; cin >> x;
    ll k = 0;
    while ((k+1)*(k+1) <= x) ++k;
    ll a = k, b = k, rem = x - k*k;
    if (rem > k) { a = k + 1; rem -= k; }
    string cur = string(a,'A') + string(b-rem,'C') + "A" + string(rem,'C');
    string s;
    rep(i,2*cur.size() - 1) s += (i % 2) ? 'R' : cur[i/2];
    cout << s << endl;
}