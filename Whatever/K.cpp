#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

vector<ll> par;
vector<ll> visited;
vector<vector<ll>> cycles;
map<ll,vector<ll>> mp;
vector<ll> cycle;
map<P,ll> ids;

set<ll> assess(vector<vector<ll>> cycles){
    map<ll,ll> arcs;
    rep(i,cycles.size()){
        for(ll j : cycles[i]){
            arcs[j]++;
        }
    }
    set<ll> atr;
    rep(i,cycles.size()){
        ll curP = cycles[i][0];
         for(ll j : cycles[i]){
            auto it = atr.lower_bound(j);
            if(*it == j) {curP = j; break;}
            curP = (arcs[j] > arcs[curP]) ? j : curP;
        }
        atr.insert(curP);
        
    }
     
    return atr;
}

void backtrack(ll cur, ll target){
    while(cur != target){
        cycle.push_back(ids[{par[cur],cur}]);
        cur = par[cur];
    }
    cycles.push_back(cycle);
}

void dfs(ll x){
    visited[x] = 1;
    for(auto i : mp[x]){
        if(visited[i] == 0){
            par[i] = x;
            dfs(i);
        }else if(visited[i] == 1){
            cycle.clear();
            cycle.push_back(ids[{x,i}]);
            backtrack(x, i);
        }
    }
    visited[x] = 2;
}
int main(){
    ll n,m;
    cin >> n >> m;
    ll a[m],b[m];
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        ids[{a[i],b[i]}]=i;
        mp[a[i]].push_back(b[i]);
    }
    par.resize(n);
    visited.resize(n,false);
    rep(i,n){
        if(!visited[i]){
            visited[i]=true;
            dfs(i);
        }
    }
    rep(i,cycles.size()){
        rep(j,cycles[i].size()){
            cout << cycles[i][j] << " ";
        }cout << endl;
    }
    set<ll> rm = assess(cycles);
    if(rm.size() > m/2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        rep(i,m){
            if(rm.find(i)==rm.end()){
                cout << i + 1<< " ";
            }
        }
        cout << endl;
    }
}