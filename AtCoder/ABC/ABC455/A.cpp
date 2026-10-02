#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    if ((A != B) && (B==C))
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    
}