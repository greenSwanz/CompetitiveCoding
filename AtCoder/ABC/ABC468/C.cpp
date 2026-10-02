#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; vector<int> P(N); vector<int> Q(N);
    vector<int> v; repp(i,1,N+1) v.push_back(i);
    rep(i,N){
        cin >> P[i];
    }
    rep(i,N){
        cin >> Q[i];
    }
    ll total = 0;
    if (P >= Q) {cout << 0 << endl; return 0;}
    do {
        if (P < v && v < Q) total++;
    } while (next_permutation(v.begin(), v.end()));
    cout << total << endl;
}