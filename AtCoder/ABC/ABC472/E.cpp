#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll T; cin >> T;
    rep(_,T){
        ll N,M; cin >> N >> M;
        vector<set<ll>> graph(N); vector<ll> colour(N,0);
        vector<ll> parent(N,-1), dep(N,0);
        rep(i,M){
            ll a,b; cin >> a >> b; a--; b--;
            graph[a].insert(b); graph[b].insert(a);
        }
        ll flag = -1, from = -1;
        queue<P> q;
        q.push({1,0}); colour[0] = 1;
        while(!q.empty() && flag == -1){
            ll temp = (q.front().first == 1) ? 2 : 1;
            ll node = q.front().second; q.pop();
            for(auto i : graph[node]){
                if(colour[i] == 0) {colour[i] = temp; parent[i] = node; dep[i] = dep[node]+1; q.push({temp,i}); continue;}
                else if(colour[i] != temp) {flag = i; from = node; break;}
            }
        }
        if(flag == -1){ cout << -1 << endl; continue; }
        ll u = from, v = flag;
        vector<ll> A, B;
        while(dep[u] > dep[v]){ A.push_back(u); u = parent[u]; }
        while(dep[v] > dep[u]){ B.push_back(v); v = parent[v]; }
        while(u != v){ A.push_back(u); B.push_back(v); u = parent[u]; v = parent[v]; }
        A.push_back(u);
        reverse(B.begin(), B.end());
        for(auto x : B) A.push_back(x);
        cout <<  A.size() << endl;
        rep(i,(ll)A.size()) cout << A[i]+1 << " "; cout << endl;
    }
}