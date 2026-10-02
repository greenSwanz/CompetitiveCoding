#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

ll H, W;
vector<ll> dx = { 1,0,-1,0,1,-1,-1,1 }, dy = { 0,1,0,-1,1,1,-1,-1 };

int main(){
    cin >> H >> W;

    char grid[H][W];

    rep(i,H){
        rep(j,W){
            cin >> grid[i][j];
        }
    }

    ll when_toggle[H][W];
    bool visited[H][W];

    queue<P> q;
    rep(i,H){
        rep(j,W){
            visited[i][j] = false;
            rep(d,8){
                ll ni = i + dx[d], nj = j + dy[d];
                if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if(grid[ni][nj] != grid[i][j]){
                    when_toggle[i][j] = 1;
                    break;
                }
            }
            if(when_toggle[i][j] == 1) {
                q.push({i,j});
                visited[i][j] = true;
            }
        }
    }

    if(q.empty()){
        rep(i,H){ rep(j,W) cout << '.'; cout << '\n'; }
        return 0;
    }

    while(!q.empty()){
        P f = q.front(); q.pop();
        ll x = f.first, y = f.second, d = when_toggle[x][y];
        rep(k,8){
            ll nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(when_toggle[nx][ny] != 1 && grid[nx][ny] == grid[x][y] && !visited[nx][ny]){
                when_toggle[nx][ny] = d + 1;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    rep(i,H){
        rep(j,W){
            if(when_toggle[i][j] % 2 == 0){
                grid[i][j] = (grid[i][j] == '.') ? '#' : '.';
            }
            cout << grid[i][j];
        }
        cout << endl;
    }
}