#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N, K, M;
    cin >> N >> K >> M;
    //no of gems
    //total gems
    //total distinct gems
    ll total_val = 0;
    set<ll> seen;
    vector<P> gems;
    vector<P> new_gems;
    gems.resize(N);
    ///value,colour
    
    rep(i,N){
        cin >> gems[i].second >> gems[i].first;
    }

    sort(gems.begin(), gems.end());
    rep(i,N){
        if(!(seen.find(gems[N-1-i].second) != seen.end()) && (seen.size() <M)){
            total_val += gems[N-1-i].first;
            seen.insert(gems[N-1-i].second);
        }
        else{
            new_gems.push_back(gems[N-1-i]);
        }
    }

    rep(i,(K-M)){
        total_val += new_gems[(K-M)-1-i].first;
    }

    cout << total_val << endl;
}