#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W; cin >> H >> W;
    vector<vector<char>> S(H,vector<char>(W)); vector<vector<bool>> visited(H,vector<bool>(W,false));
    rep(i,H) rep(j,W) cin >> S[i][j]; ll x = 0; ll y = 0; ll total = 0;  
    while(x < H && y < W){
        if(!visited[x][y] && S[x][y] == '.'){
            bool inside = true;
            visited[x][y] = true;
            queue<P> q;
            q.push({x,y});
            while(!q.empty()){
                P p = q.front(); q.pop();
                if(p.first == 0 || p.first == H-1 || p.second == 0 || p.second == W-1) inside = false;
                repp(i,max(0LL,p.first-1),min(H,p.first+2)) repp(j,max(0LL,p.second-1),min(W,p.second+2)){
                    if(abs(i-p.first) + abs(j-p.second) != 1) continue;
                    if(!visited[i][j] && S[i][j] == '.'){ visited[i][j] = true; q.push({i,j}); }
                }
            }
            if(inside) total++;
        }
        visited[x][y] = true;
        x += (y + 1 == W)  ? 1 : 0;
        y = (y + 1 == W) ? 0 : (y+1);
    }
    cout << total << endl;
}