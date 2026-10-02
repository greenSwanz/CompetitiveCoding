#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

ll power(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N+1,0),B(N+1,0);
    repp(i,1,N+1) cin >> A[i];
    repp(i,1,N+1){
        if(B[i] == 0){
            vector<ll> t;
            t.push_back(i);
            ll temp = A[i];
            while(temp != A[temp]){
                t.push_back(temp);
                temp = A[temp];
            }
            for (auto j : t) B[j] = temp;
        }
    } 
    repp(i,1,N+1){
        cout << B[i] << " ";
    }   
}