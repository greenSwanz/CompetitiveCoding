#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W,Q;
    cin >> H >> W >> Q;
    vector<vector<ll>> cumsum_grid(H, vector<ll>(W));
    rep(i,H) rep(j,W) cumsum_grid[i][j] = 0;
    ll R,C;
    vector<char> X(Q+1); X[0] = 'A';
    rep(i,Q) {
        cin >> R >> C >> X[i+1];
        cumsum_grid[R-1][C-1] = i+1;        
    }
    rep(i,H){
        rep(j,W){
            ll temp_x = cumsum_grid[H-i-1][W-j-1];
            ll temp_y = cumsum_grid[H-i-1][W-j-1];
            if(i != 0) temp_x = max(temp_x, cumsum_grid[H-i][W-j-1]);
            if(j != 0) temp_y = max(temp_y, cumsum_grid[H-i-1][W-j]);
            cumsum_grid[H-i-1][W-j-1] = max(temp_x,temp_y);
        }
    }
    rep(i,H){
        rep(j,W) cout << X[cumsum_grid[i][j]];
        cout << endl;
    } 
}