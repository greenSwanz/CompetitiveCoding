#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll N,M; cin >> N >> M;
    unordered_map<ll,ll> rows, cols;
    vector<P> queries(M);
    ll total = 0;
    rep(i,M) {
        ll R,C; cin >> R >> C;
        queries[i].first = R; queries[i].second = C;
         rows[R] = i; cols[C] = i;
    }
    rep(i,M){
        if(rows[queries[i].first] == i && cols[queries[i].second] == i) total++;
    }
    cout << total << endl;    
}