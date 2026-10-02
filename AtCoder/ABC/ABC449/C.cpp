#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,L,R; cin >> N >> L >> R; string S; cin >> S;
    map<char,vector<ll>> m; rep(i,N) m[S[i]].push_back(i);
    ll total = 0;
    for(auto i : m){
        for (auto j : i.second){
            auto left = lower_bound(i.second.begin(), i.second.end(),L+ j);
            auto right = upper_bound(i.second.begin(), i.second.end(),R+ j);
            total += (right - left);
        }
    }
    cout << total << endl;
}