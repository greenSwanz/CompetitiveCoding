#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W; cin >> H >> W;
    vector<vector<ll>> grid(H,vector<ll>(W,0));
    rep(i,H) {
        rep(j,W) {
            if(i-1 >= 0) grid[i][j]++;
            if(j-1 >= 0) grid[i][j]++;
            if(j+1 <= W-1) grid[i][j]++;
            if(i+1 <= H-1) grid[i][j]++;
        }
    }
    rep(i,H) { rep(j,W) { cout << grid[i][j] << " ";} cout << endl;}
}