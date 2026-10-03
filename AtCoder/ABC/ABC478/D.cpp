#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q; cin >> N >> Q;
    vector<vector<ll>> op(Q,vector<ll>(3));
    rep(i,Q){
        ll l,r,x; cin >> l >> r >> x; l--; r--; op[i] = {x,l,r};
    }
    sort(op.begin(),op.end());
    vector<ll> cur = op[0];
    vector<ll> sums(N+1,0); sums[cur[1]]++; sums[cur[2]+1]--;
    repp(i,1,Q){
        if(op[i][0] == cur[0]){
            if(op[i][1] > cur[2]){
                sums[op[i][1]]++; sums[op[i][2]+1]--;
                cur = op[i];
            }
            else{
                ll nl = min(cur[1], op[i][1]), nr = max(cur[2], op[i][2]);
                sums[cur[1]]--; sums[cur[2]+1]++;
                sums[nl]++; sums[nr+1]--;
                cur = {cur[0], nl, nr};
            }
        }
        else{
            sums[op[i][1]]++; sums[op[i][2]+1]--;
            cur = op[i];
        }
    }
    cout << sums[0] << " ";
    repp(i,1,N){
        sums[i] += sums[i-1];
        cout << sums[i] << " ";
    }
    cout << endl;
}