#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W; cin >> H >> W;
    vector<string> grid(H);
    rep(i,H){
        cin >> grid[i];
    }
    ll total = 0;
    bool flag = true;
    rep(i,H){
        repp(j,i,H){
            rep(k,W){
                repp(l,k,W){
                    repp(x,i,j+1){
                        repp(y,k,l+1){
                            if(grid[x][y] != grid[i+j-x][k+l-y]) flag = false;
                        }
                    }
                    if(flag) total++;
                    flag = true;
                }
            }
        }
    }
    cout << total << endl;
}