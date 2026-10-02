#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int N,Q;
map<ll,vector<ll>> edges;
vector<bool> visited;
vector<int> points;

void dfs(int current_node, int current_sum){
    visited[current_node]=true;
    points[current_node] = current_sum;

    rep(i,edges[current_node].size()){
        if(edges.find(edges[current_node][i]) != edges.end()){
            if(!visited[edges[current_node][i]]){
                dfs(edges[current_node][i], current_sum+points[(edges[current_node][i])]);
            }
        }
        else{
            points[(edges[current_node][i])] += current_sum;
        }
    }

}


int main(){
    
    cin >> N >> Q;
    points.resize(N+1);
    visited.resize(N+1);
    rep(i,N-1){
        int temp, temp2;
        cin >> temp >> temp2;

        if (edges.find(temp) != edges.end()){
            edges[temp].push_back(temp2);
        }
        else{
            edges.insert({temp,{temp2}});
        }
        if (edges.find(temp2) != edges.end()){
            edges[temp2].push_back(temp);
        }
        else{
            edges.insert({temp2,{temp}});
        }
        
    }


    rep(i,N){
        points[i] = 0;
    }

    rep(i,Q){
        int temp, temp2;
        cin >> temp >> temp2;
        points[temp] += temp2;
    }
    /*
    rep(i,Q){
        if(points[i] != 0){
            dfs(i, points[i]);
        }
    }
        */

    dfs(1,points[1]);

    rep(i,N){
        cout << points[i+1] << " ";
    }
    cout << endl;
}