#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

ll N,K; 
vector<set<ll>> adj;
vector<ll> depth;
vector<ll> tracker;

void dfs(ll cur_node){
    bool nice = adj[cur_node].size() == 1;
    depth[cur_node] = tracker.size() >= K ? tracker[tracker.size() - K] : -1;
    if(nice) tracker.push_back(cur_node);
    for(auto i : adj[cur_node]) dfs(i);
    if(nice) tracker.pop_back();    
}

int main(){
    ll T; cin >> T;
    rep(_,T){
        adj.clear(); depth.clear();tracker.clear();
        cin >> N >> K;
        vector<ll> parents(N); adj.resize(N);
        repp(i,1,N) { cin >> parents[i]; adj[(parents[i] -1)].insert(i);}
        depth.resize(N,-1);
        dfs(0);
        rep(i,N) cout << (depth[i] == -1 ? -1 : depth[i]+1) << " "; cout << endl;
    }
}