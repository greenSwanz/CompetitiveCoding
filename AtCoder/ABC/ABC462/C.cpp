#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<P> coords(N);
    vector<P> reversed_c(N);
    set<P> allowed_coords;
    rep(i,N){
        cin >> coords[i].first >> coords[i].second;
    }
    sort(coords.begin(), coords.end());
    ll ans = 0; 
    ll minY = N;
    rep(i,N){
        if(coords[i].second < minY){
            ans++;
            minY = coords[i].second;
        }
    }
    cout << ans << endl;
}