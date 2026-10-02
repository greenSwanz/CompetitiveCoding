#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

const ll M = 1000001;
vector<ll> spf(M);

void build(){
    rep(i,M) spf[i] = i;
    for(ll i = 2; i*i < M; ++i)
        if(spf[i] == i)
            for(ll j = i*i; j < M; j += i)
                if(spf[j] == j) spf[j] = i;
} //note down, makes a table with smallest prime number dividing into it 

int main(){
    build();
    ll T; cin >> T;
    rep(_,T){
    ll N; cin >> N; vector<ll> A(N);
    map<ll,ll> dups; set<ll> keys;
    rep(i,N) cin >> A[i];
    ll total = 0;
    vector<ll> res(N,1);
    rep(i,N){
        ll temp = A[i];
        while(temp > 1) {
            ll p = spf[temp], c = 0;
            while(temp % p == 0) { temp /= p; ++c; }
            if(c & 1) res[i] *= p;
        }
        //if(temp > 1) res[i] *= temp;
        dups[res[i]]++; keys.insert(res[i]);
    }
    for(auto i : dups) total += i.second * (i.second - 1) / 2;
    cout << total << endl;
}
}