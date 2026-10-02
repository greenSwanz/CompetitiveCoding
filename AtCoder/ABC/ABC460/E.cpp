#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

ll p = 998244353;
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a % b); }
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll N,M;
        cin >> N >> M;
        ll Y = 0; ll t = N; while(t > 0){ t /= 10; Y++; }
        ll a = 9 % M; ll curr_x = 0; ll total_y = 0;
        ll lo = 1;
        rep(_,Y){
            ll g = gcd(a,M);
            curr_x = N / (M / g);
            a = ((a *10) +9) % M;
            ll hi = (lo > N / 10) ? N : lo * 10 - 1; 
            total_y = (total_y + curr_x % p * ((hi - lo + 1) % p)) % p;
            if(lo > N / 10) break; lo *= 10;
        }
        cout << total_y << endl;
    }
}