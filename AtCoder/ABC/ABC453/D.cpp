#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W; cin >> H >> W; vector<vector<char>> grid(H,vector<char>(W)); P start,goal;
    rep(i,H) rep(j,W) {cin >> grid[i][j]; if(grid[i][j] == 'S') {start = {i,j};} if(grid[i][j] == 'G') {goal = {i,j};}}
    //queue<pair<string,P>> q;
    queue<tuple<ll,ll,char>> q;
    vector<vector<vector<tuple<ll,ll,ll>>>> parent(H, vector<vector<tuple<ll,ll,ll>>>(W, vector<tuple<ll,ll,ll>>(4, {-1,-1,0})));
    vector<pair<char,P>> dirs = {{'U',{-1,0}}, {'D',{1,0}}, {'L',{0,-1}}, {'R',{0,1}}};
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(4, false)));
    map<char,ll> m; m['L'] = 0; m['R'] = 1; m['U'] = 2; m['D'] = 3;
    for (auto p : dirs) {
        ll nx = start.first + p.second.first, ny = start.second + p.second.second;
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if(grid[nx][ny] == '#') continue;
        q.push({nx,ny,p.first});
        visited[nx][ny][m[p.first]] = true;
    }
    while(!q.empty()){
        auto [x,y,d] = q.front(); q.pop();
        if(P{x,y} == goal){
            string path; 
            ll cx = x, cy = y, cd = m[d];
            while(cx != -1){
                path += (cd == 0 ? 'L' : cd == 1 ? 'R' : cd == 2 ? 'U' : 'D');
                auto [pr,pc,pd] = parent[cx][cy][cd];
                cx = pr; cy = pc; cd = pd;
            }
            reverse(path.begin(), path.end());
            cout << "Yes" << endl; cout << path << endl; return 0;
        }
        for (auto p : dirs) {
            ll nx = x + p.second.first, ny = y + p.second.second;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(grid[x][y] == 'x' && d == p.first) continue;
            if(grid[x][y] == 'o' && d != p.first) continue;
            if(grid[nx][ny] == '#') continue;
            if(visited[nx][ny][m[p.first]]) continue;
            parent[nx][ny][m[p.first]] = {x,y,(ll) m[d]};
            q.push({nx,ny,p.first});
            visited[nx][ny][m[p.first]] = true;
        }
    }
    cout << "No" << endl;
}