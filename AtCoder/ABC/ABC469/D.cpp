#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M; cin >> N >> M;
    vector<ll> sums(N+1,0);
    unordered_map<ll,ll> bad;
    ll A, B;
    rep(i, M) {
        ll a,b;
        cin >> a >> b;
        if(i==0){A = a; B = b;};
        sums[a]++; sums[b]++;
        bad[a * N + b]++; 
    }
    ll pairs = 0;
    repp(i,1,N+1){
        if (i != A && sums[i] + sums[A] - bad[min(A,i)*N+max(A,i)] == M) pairs++;
    }
    repp(i,1,N+1){
        if (i != B && sums[i] + sums[B] - bad[min(B,i)*N+max(B,i)] == M) pairs++;
    }
    if(sums[A]+sums[B]-bad[A*N+B] ==M) pairs--;
    cout << pairs << endl;
}