#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K; cin >> N >> M >> K;
    ll X,Y; cin >> X >> Y; vector<P> s;
    vector<ll> n(N); rep(i,N) {cin >> n[i]; s.push_back({n[i],1});}
    vector<ll> m(M); rep(i,M) {cin >> m[i]; s.push_back({m[i],0});}
    sort(s.begin(),s.end());
    ll V = X + K*Y;
    ll total = 0;
    ll i = 0;
    while(i < (ll)s.size()){
        if(s[i].first > V) break;
        if(s[i].second == 0){
            ll c = (s[i].first + K - 1) / K;
            if(c > Y){ i++; continue; }
            Y -= c;
        }
        V -= s[i].first; total++;
        i++;
    }
    cout << total << endl;
}