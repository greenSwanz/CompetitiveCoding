#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W,K; cin >> H >> W >> K; vector<vector<char>> s(H,vector<char>(W));
    rep(i,H) rep(j,W) cin >> s[i][j];
    vector<bool> safe_rows(H,true); vector<bool> safe_cols(W,true); vector<P> safe_coords;
    rep(i,H) rep(j,W) {if(s[i][j] == '#') {safe_rows[i] = false; safe_cols[j] = false;}}
    rep(i,H) rep(j,W) {if(safe_rows[i] && safe_cols[j]) safe_coords.push_back({i,j});}
    vector<vector<bool>> visited(H,vector<bool>(W,false));
    queue<pair<ll,P>> q;
    for(auto i : safe_coords) {q.push({1,i}); visited[i.first][i.second] = true;}
    while(!q.empty() && (q.front().first <= K)){
        ll i = q.front().first; ll x = q.front().second.first;
        ll y = q.front().second.second; q.pop();
        if(!visited[max(0LL,x)][max(0LL,y-1)]) {visited[max(0LL,x)][max(0LL,y-1)] = true; q.push({i+1,{max(0LL,x), max(0LL,y-1)}}); }
        if(!visited[max(0LL,x-1)][max(0LL,y)]) {visited[max(0LL,x-1)][max(0LL,y)] = true; q.push({i+1,{max(0LL,x-1), max(0LL,y)}}); }
        if(!visited[min(H-1,x+1)][max(0LL,y)]) {visited[min(H-1,x+1)][max(0LL,y)] = true; q.push({i+1,{min(H-1,x+1), max(0LL,y)}}); }
        if(!visited[max(0LL,x)][min(W-1,y+1)]) {visited[max(0LL,x)][min(W-1,y+1)] = true; q.push({i+1,{max(0LL,x), min(W-1,y+1)}}); }
    }
    ll total = 0;
    rep(i,H) {
        rep(j,W){
            if(visited[i][j] && (s[i][j] == '.')) total++;
        }
    }
    cout << total << endl;
}