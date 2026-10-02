#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N, K, X;
    cin >> N >> K >> X;
//N is no of bottles
// K is number with sake
// X is sake that needs to be drunk
    ll A[N];
    rep(i,N){
        cin >> A[i];
    }
    sort(A, A + N);
    ll minimum_sake = 0;
    rep(i,K){
        minimum_sake += A[i];
    }
    
    ll max_sake_can_waste = minimum_sake - X;
    if (max_sake_can_waste < 0){
        cout << -1 <<  endl;
        return 0;
    }
    
    ll temp = 0;
    rep(i,K){
        temp += A[i];
        if (temp > max_sake_can_waste){
            cout << (N- i) << endl;
            return 0;
        }
        else if (temp == max_sake_can_waste){
            cout << (N - i - 1) << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;

}