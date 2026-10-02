#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll p = 1000000007;

ll fact(ll num){
    ll f = 1;
    repp(i,2,num+1) f = (f * i) % p;
    return f;
}

ll power(ll a, ll b, ll p){
    ll res = 1;
    a %= p;
    while (b > 0){
        if(b & 1) res = (res * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    ll X,Y;
    cin >> X >> Y;
    if ((X+Y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    ll total_moves = ((X+Y)/3);
    ll a = (total_moves + Y - X)/2;
    if (a < 0 || a > total_moves || (total_moves + Y - X) % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }   
    ll total_moves_fact  = fact(total_moves);
    ll a_inv_fact = fact(a);
    ll ta_inv_fact = fact(total_moves - a);
    ll D = a_inv_fact * ta_inv_fact % p;
    ll res = total_moves_fact * power(D,p-2,p) % p;
    cout << res << endl;
}