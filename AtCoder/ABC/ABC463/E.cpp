#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,Y;
    cin >> N >> M >> Y;
    map<ll,vector<P>> tree;
    rep(i,M){
        ll u,v,t;
        cin >> u >> v >> t;
        tree[u-1].push_back({v-1,t});
        tree[v-1].push_back({u-1,t});
    }
    rep(i,N){
        ll x;
        cin >> x;
        tree[i].push_back({N,x});
        tree[N].push_back({i,x+Y});
    }

    map<ll, ll> dist;
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        auto it = dist.find(u);
        if(it != dist.end() && d > it->second) continue;

        for(auto& [v, w] : tree[u]){
            ll new_d = d + w;
            auto jt = dist.find(v);
            if(jt == dist.end() || new_d < jt->second){
                dist[v] = new_d;
                pq.push({new_d, v});
            }
        }
    }
    repp(i,1,N) cout << dist[i] << " ";
}