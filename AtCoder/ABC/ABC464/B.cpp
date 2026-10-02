#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    vector<P> keep;
    rep(i,H){
        rep(j,W){
            cin >> grid[i][j];
            if(grid[i][j] == '#'){
                keep.push_back({i, j});
            }
        }
    }

    sort(keep.begin(), keep.end());
    ll top, bottom;
    top = keep[0].first;
    bottom = keep[keep.size()-1].first;
    vector<P> back;
    rep(i, keep.size()){
        if(keep[i].first >= top && keep[i].first <= bottom){
            back.push_back({keep[i].second, keep[i].first});
        }
    }
    sort(back.begin(), back.end());
    ll left, right;
    left = back[0].first;
    right = back[back.size()-1].first;
    repp(i, top, bottom+1){    
        repp(j, left, right+1){
            cout << grid[i][j];
        }
        cout << endl;
    }
}