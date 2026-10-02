#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i = 0; i < (n); ++i)

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    vector<ll> B(M);
    vector<ll> maxWeights(N);

    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    
    ll counter = 0;
    rep(i,N){
        auto it = std::upper_bound(B.begin(), B.end(), A[i]*2);
        if((it - B.begin()) > counter){
            counter++;
        }
    }
    

    cout << counter << endl;
    return 0;
}
