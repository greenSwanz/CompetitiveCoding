#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int counter = 0;
int H,W;

void dfs(int u, int target, bool visited[], vector<int>& nums_seen, int grid[], vector<int>& paths){
    visited[u] = true;
    nums_seen.push_back(grid[u]);
    paths.push_back(u);

    if(u == target){
        if(find(nums_seen.begin(), nums_seen.end() -1, grid[u]) == nums_seen.end() -1){
            counter += 1;    
        }        
    }
    else{
        int temp = u; 
        int below = u + W; 
        int right = u + 1; 
        
        if((((temp/W)*W) <= right) && (right <= ((temp/W + 1)*W - 1)) && (right < H*W) && (!visited[right])){
            if(find(nums_seen.begin(), nums_seen.end(), grid[right]) == nums_seen.end()){
                dfs(right,target,visited,nums_seen,grid,paths);
            }
        }
        if(((0 <= below) && (below < (H*W))) && (!visited[below])){
            if(find(nums_seen.begin(), nums_seen.end(), grid[below]) == nums_seen.end()){
                dfs(below,target,visited,nums_seen,grid,paths);
            }
        }
    }

    
    paths.pop_back();
    nums_seen.pop_back(); 
    visited[u] = false;
}

int main(){
    if(!(cin >> H >> W)) return 0;

    int A[H*W];
    rep(i,(H*W)){
        cin >> A[i];
    }
    
    bool visited[H*W] = {};
    
    vector<int> nums_seen;
    vector<int> paths;
    
    dfs(0,(H*W-1),visited,nums_seen,A, paths);
    cout << counter << endl;
    return 0;
}