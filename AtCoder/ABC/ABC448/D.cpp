#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
vector<bool> tracker;
vector<set<int>> m;
vector<bool> visited;
vector<int> A;
set<int> s;
void dfs(int node, bool parent){
    visited[node] = true;
    bool old; if((s.find(A[node])!=s.end())) old = true;
    if(parent || old) tracker[node] = true; 
    s.insert(A[node]);
    for(auto i : m[node]) {if(!visited[i]) dfs(i,tracker[node]);}
    if(!old) s.erase(A[node]);
}
int main(){
    int N; cin >> N;
    tracker.assign(N,false);
    m.assign(N,set<int>());
    A.resize(N);
    visited.assign(N,false);
    //vector<int> A(N); 
    rep(i,N) cin >> A[i];
    //vector<set<int>> m(N); 
    rep(i,N-1) {int u,v; cin >> u >> v; u--; v--; m[u].insert(v); m[v].insert(u);}
    //vector<bool> visited(N,false); 
    //vector<bool> tracker(N,false); 
    //vector<set<int>> vals(N);
    /*queue<int> q; visited[0] = true; tracker[0] = false; vals[0].insert(A[0]); 
    for(auto i : m[0]) {
        visited[i] = true;
        q.push(i);
        if(vals[0].count(A[i])){
            tracker[i] = true;
        }
        vals[i] = vals[0];
        vals[i].insert(A[i]);
    }
    while(!q.empty()){
        int p = q.front(); q.pop();
        for(auto i : m[p]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                if((vals[p].count(A[i])) || tracker[p]){
                    tracker[i] = true;
                }
                if(!tracker[i]){
                vals[i] = vals[p];
                vals[i].insert(A[i]);}
            }
        }
        set<int>().swap(vals[p]);
    }*/
   dfs(0,false);
    rep(i,N){
        if(tracker[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}