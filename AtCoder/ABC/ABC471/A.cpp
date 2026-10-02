#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A,B; cin >> A >> B;
    if((A*B == 9) || (A+B == 9) || (A == 9 * B) || (A == 9 + B)) cout << "Nine" << endl;
    else cout << "Nein" << endl;
}