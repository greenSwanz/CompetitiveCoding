#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> days(M);
    vector<vector<ll>> col_out(M);
    ll A,B,D;
    rep(i,N){
        cin >> A >> D >> B;
        if(D-1 != 0){
            days[0].push_back(A);
            col_out[D-1].push_back(A);
        }
        days[D-1].push_back(B);
    }
    map<ll,ll> cnt;
    set<ll> t = {};
    for (ll x : days[0]){ if(cnt[x]++ == 0) t.insert(x); }
    rep(i,M){
        if(i != 0){
            for (ll x : col_out[i]){ if(--cnt[x] == 0) t.erase(x); }
            for (ll x : days[i]){ if(cnt[x]++ == 0) t.insert(x); }
        }
        cout << t.size() << endl;
    }
}