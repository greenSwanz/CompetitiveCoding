#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W,K;
    cin >> H >> W >> K;
    ll grid[H][W];
    vector<string> rows;
    rep(i,H){
        string t;
        cin >> t;
        rows.push_back(t);
        rep(j,W){
            grid[i][j] = (rows[i][j] == '1') ? 1 : 0;
        }
    }
    ll total = 0;
    ll left,right;
    vector<ll> cumsum_col(W+1);
    vector<ll> cumsum(W+1);
    cumsum[0] = 0; cumsum_col[0] = 0;
    rep(r1,H){
        rep(i,W+1) cumsum_col[i]=0;
        repp(r2,r1,H){
            repp(i,1,W+1) cumsum[i]=grid[r2][i-1] + cumsum[i-1];
            repp(i,1,W+1) cumsum_col[i]+=cumsum[i];
            right = 1;
            rep(left,W+1){
                while(right<W+1){
                    ll cur_sum = cumsum_col[right] - cumsum_col[left];
                    if(cur_sum<=K) right++;
                    else if(cur_sum>K)break;
                }
                total+=right-left-1;
                if (right == left) right++;
            }
            if(K!=0){
                right = 1;
                rep(left,W+1){
                    while(right<W+1){
                        ll cur_sum = cumsum_col[right] - cumsum_col[left];
                        if(cur_sum<=K-1) right++;
                        else if(cur_sum>K-1)break;
                    }
                    total-=right-left-1;
                    if (right == left) right++;
                }
            }
        }
    }
    cout << total << endl;
}