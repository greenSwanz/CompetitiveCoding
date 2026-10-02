#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;

    vector<vector<ll>> grid(10,vector<ll>(10));
    rep(i,10){
        rep(j,10){
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> wall(H,vector<ll>(W));
    rep(i,H){
        rep(j,W){
            cin >> wall[i][j];
        }
    }

    rep(i,10){
        rep(x,10){
            rep(y,10){
                if(grid[x][y] > grid[x][i] + grid[i][y]){
                    grid[x][y] = (grid[x][i]) + (grid[i][y]);
                }                   
            }
        }
    }

    ll mp = 0;

    rep(i,H){
        rep(j,W){
            if(wall[i][j] > -1){
                mp += grid[(wall[i][j])][1];
            }
        }
    }

    cout << mp << endl;
    return 0;



}