#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll temp = 0;
    if (X>Y)
    {
        temp = min(A*X + B*Y, min(2*C*X, 2*C*Y + A*(X-Y)));
    }
    else
    {
        temp = min(A*X + B*Y, min(2*C*Y, 2*C*X + B*(Y-X)));
    } 
    cout << temp << endl;
    return 0;


}