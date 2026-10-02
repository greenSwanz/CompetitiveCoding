#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

vector<P> edges;
vector<pair<ll,set<ll>>> adjList;
vector<ll> visited;

void dfs(ll node){
    visited.push_back(node);
    for (auto n : adjList[node].second){
        if (find(visited.begin(), visited.end(), n) == visited.end()){
            dfs(n);
        }
    }
}

int main(){
    ll N,M;

    cin >> N >> M;
    adjList.resize(N);

    rep(i,N){
        adjList[i].first = i;
    }

    ll A[M];
    ll B[M];

    rep(i,M){
        cin >> A[i] >> B[i];
        edges.push_back({A[i]-1, B[i]-1});
        adjList[A[i]- 1].second.insert(B[i]-1);
        adjList[B[i]- 1].second.insert(A[i]-1);
    }

    ll counter = 0;

    rep(i,M){
        adjList[edges[i].first].second.erase(edges[i].second);
        adjList[edges[i].second].second.erase(edges[i].first);
        visited.clear();
        dfs(0);
        if(visited.size() != N){
            counter++;
        }
        adjList[edges[i].first].second.insert(edges[i].second);
        adjList[edges[i].second].second.insert(edges[i].first);
    }

    cout << counter << endl;
}