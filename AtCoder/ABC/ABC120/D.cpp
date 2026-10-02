#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

vector<ll> parents;
vector<ll> num_children;

ll find(ll child){
    if(parents[child] != child){
        return parents[child] = find(parents[child]);
    }
    return parents[child];
}

void join(ll parent, ll child){
    parent = find(parent);
    child = find(child);
    parents[child] = parent;
    num_children[parent] += num_children[child];

}

int main(){
    ll M,N;

    cin >> N >> M;

    parents.resize(N);
    num_children.resize(N);
    vector<ll> outputs;
    outputs.resize(M);

    ll num_pairs = N*(N-1)/2;

    rep(i,N){
        parents[i] = i;
        num_children[i] = 1;
    }

    ll A[M];
    ll B[M];

    rep(i,M){
        cin >> A[M - i - 1] >> B[M - i - 1];
    }

    outputs[M-1] = num_pairs;

    rep(i, M -1) {
    if (find(A[i]-1) != find(B[i]-1)) {
        num_pairs -= num_children[find(A[i]-1)] * num_children[find(B[i]-1)];
        join(A[i]-1, B[i]-1);
    }
    outputs[M-i-2] = num_pairs;
    }

    rep(i,M){
        cout << outputs[i] << endl;
    }
}
