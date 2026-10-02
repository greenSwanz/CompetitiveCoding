#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W,N; cin >> H >> W >> N; vector<pair<P,ll>> p(N); vector<pair<P,ll>> sortp(N); vector<P> coords(N);
    rep(i,N){
        //cin >> p[i].first.first >> p[i].first.second;
        cin >> p[i].first.second >> p[i].first.first;
        sortp[i].first.first = p[i].first.second; sortp[i].first.second = p[i].first.first;
        sortp[i].second = i;
    }
    ll curh = H, curw = W;
    sort(sortp.begin(),sortp.end()); reverse(sortp.begin(),sortp.end());
    vector<pair<P,ll>> revp(N);
    rep(i,N){
        revp[i].first.first = sortp[i].first.second; revp[i].first.second = sortp[i].first.first;
        revp[i].second = sortp[i].second;
    }
    sort(revp.begin(),revp.end());
    reverse(revp.begin(),revp.end());
    vector<bool> used(N,false); ll a = 0, b = 0;
    rep(k,N){
        while(used[sortp[a].second]) a++;
        while(used[revp[b].second]) b++;
        if(sortp[a].first.first == curh){
            coords[sortp[a].second] = {1, curw - sortp[a].first.second + 1};
            curw -= sortp[a].first.second;
            used[sortp[a].second] = true;
        } else { 
            coords[revp[b].second] = {curh - revp[b].first.second + 1, 1};
            curh -= revp[b].first.second;
            used[revp[b].second] = true;
        }
    }
    rep(i,N){
        cout << coords[i].first << " " << coords[i].second << endl;
    }
}