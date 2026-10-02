#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

vector<ll> parents;
vector<pair<double,P>> edges;

ll find(ll node){
    if(parents[node] != node)
        parents[node] = find(parents[node]);
    return parents[node];
}

void join(ll node_parent, ll node_child){
    parents[node_child] = node_parent;
}

/*
vector<ll> paren;
int parent(ll x){
    if(x == paren[x]) return x;
    return paren[x] = parent(paren[x]);
}
void merge(ll a,ll b){
    paren[parent(a)] = parent(b);
}
*/

int main(){
    ll N;       
    double length;

    while(cin >> N && N != 0){

        edges.clear();
        parents.clear();
        
        double X[N];
        double Y[N];
        double Z[N];
        double R[N];
        
        parents.resize(N);
        rep(i,N){
            parents[i] = i;
        }

        length = 0;

        rep(i,N){
            cin >> X[i] >> Y[i] >> Z[i] >> R[i];
        }

        rep(i,N){
            repp(j,i+1,N){
                double dist = max(0.0, sqrt(pow((X[i]-X[j]),2) + pow((Y[i]-Y[j]),2) + pow((Z[i]-Z[j]),2)) - R[i] - R[j]);
                edges.push_back({dist, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());
        
        rep(i,edges.size()){
            if(!(find(edges[i].second.first) == find(edges[i].second.second))){
                length += edges[i].first;
                join(find(edges[i].second.first), find(edges[i].second.second));
            }
        }

        cout << fixed << setprecision(3) << length << endl;
    

}
}