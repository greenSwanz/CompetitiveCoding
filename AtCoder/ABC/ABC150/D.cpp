#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) {
    ll d = GCD(a, b);
    return a / d * b;
}
int main(){
    ll N, M;
    cin >> N >> M;
    ll A[N];
    cin >> A[0];
    A[0] /= 2;
    ll minX = A[0];
    repp(i,1,N){
        cin >> A[i];
        A[i] /= 2;
        if ((((A[i]/GCD(A[i],A[0])) % 2) == ((A[0]/GCD(A[i],A[0])) % 2)) && (minX <= M)) minX = LCM(minX, A[i]);
        else {
            cout << 0 << endl;
            return 0;
        }
    }
    ll temp2 = (M / minX);
    cout << ((temp2/2) + (temp2%2)) << endl;
}

