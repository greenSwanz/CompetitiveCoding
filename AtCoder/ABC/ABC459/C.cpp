#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N, Q;
    cin >> N >> Q;

    map<ll,ll> m;
    map<ll,set<ll>> backwards;

    rep(i,N){
        m.insert({i,0});
    }

    rep(i,Q){
        backwards.insert({i,{}});
    }

    int penalty = 0;
    rep(i,Q){
        ll x;
        ll y;
        cin >> x >> y;

        if(x == 1){
            m[y]++;
            backwards[m[y]].insert(y);
            if(backwards[1+penalty].size() == N){
                penalty++;
            }
        }
        else{
            cout << (backwards[y+penalty].size()) << endl;
        }
    }

}