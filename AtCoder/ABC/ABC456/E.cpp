#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

ll W; 
map<ll,set<ll>> visited;
map<ll,set<ll>> m;
vector<vector<bool>> holiday;
vector<vector<ll>> col;

bool dfs(ll a, ll d){
    if(col[a][d%W] == 2) return false;
    if(col[a][d%W] == 1) return true;
    col[a][d%W] = 1;
    for(auto i : m[a]){
        if(holiday[i][(d+1) % W] && dfs(i, d+1)) { col[a][d%W] = 1; return true;}
    }
    if(holiday[a][(d+1) % W] && dfs(a, d+1)){ col[a][d%W] = 1; return true; } 
    col[a][d%W] = 2;
    return false;
}

int main(){
    ll T; cin >> T;
    rep(_,T){
        ll N,M; cin >> N >> M; 
        m.clear(); visited.clear(); 
        rep(i,M){
            ll u,v; cin >> u >> v;
            m[u].insert(v); m[v].insert(u);
        }
        cin >> W; 
        col.assign(N+1,vector<ll>(W,0));
        vector<string> grid(N+1);
        holiday.assign(N+1,vector<bool>(W,false));
        repp(i,1,N+1){
            cin >> grid[i];
            rep(j,W){
                if(grid[i][j] == 'o') holiday[i][j] = true;
            }
        }
        bool flag = false;
        repp(j,1,N+1){
            //visited.clear();
            if(holiday[j][0]) flag = flag || dfs(j,0);
        }
        cout << ((flag) ? "Yes" : "No") << endl;
    }
}