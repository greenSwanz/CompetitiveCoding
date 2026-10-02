#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
ll N; vector<ll> cur;
void dfs(ll index, ll curK){
    if(index == N) { 
        if (curK % N == 0) {
            cur.push_back(curK / N);
            for (ll x : cur) cout << x << " "; cout << '\n';
            cur.pop_back();
        }}
    else{
        rep(i,(curK/index)+1){
            cur.push_back(i);
            dfs(index+1,curK-(i*index));
            cur.pop_back(); }
    }    
}
int main(){
    ll K; cin >> N >> K;
    dfs(1,K);
}