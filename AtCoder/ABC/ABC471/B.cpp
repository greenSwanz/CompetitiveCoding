#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; map<string,ll> m;
    rep(i,N){
        string temp; cin >> temp;
        for (auto& x : temp) {
            x = tolower(x);
        }
        m[temp]++;
    }
    ll M = 0;
    for(auto i : m){
        M = max(M, i.second);
    }
    cout << M << endl;
}