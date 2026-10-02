#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
class UnionFind {
    vector<int> parent;
public:
    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return find(parent[i]);
    }
    void unite(int i, int j) {
        int irep = find(i);
        int jrep = find(j);
        parent[irep] = jrep;
    }
};
int main(){
    ll V,E;
    cin >> V >> E;
    vector<pair<ll,P>> vew;
    ll total_weight = 0;
    vew.resize(E);
    UnionFind uf(V);
    rep(i,E){
        cin >> vew[i].second.first >> vew[i].second.second >> vew[i].first;
    }
    sort(vew.begin(), vew.end());
    rep(i,E){
        if(uf.find(vew[i].second.first) != (uf.find(vew[i].second.second))){
            total_weight += vew[i].first;
            uf.unite(vew[i].second.first, vew[i].second.second);
        }
    }

    cout << total_weight << endl;
}