#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M; cin >> N >> M; vector<ll> nums(N+1,N+1);
    vector<P> pairs(M); vector<P> reversed_pairs(M);
    rep(i,M) {
        cin >> pairs[i].first >> pairs[i].second;
        reversed_pairs[i].first = pairs[i].second;
        reversed_pairs[i].second = pairs[i].first;
        nums[pairs[i].first] = min(pairs[i].second,nums[pairs[i].first]);
    }
    repp(i,1,N+1){
        nums[N-i] = min(nums[N-i],nums[N+1-i]);
    }
    sort(pairs.begin(), pairs.end());
    sort(reversed_pairs.begin(),reversed_pairs.end());
    ll Q; cin >> Q;
    rep(i,Q){
        ll l,r; cin >> l >> r;
        auto it = lower_bound(pairs.begin(),pairs.end(), P(l,r)) - pairs.begin();
        if(it < M && pairs[it] == P(l,r)){
            if(it +1 < M && pairs[it+1] == P(l,r) || (nums[l+1] <= r))  {cout << "Yes" << endl; continue;}
        } 
        auto idx2 = lower_bound(reversed_pairs.begin(), reversed_pairs.end(), P(r,l)) - reversed_pairs.begin();
        auto idx = (idx2 < M) ? lower_bound(pairs.begin(), pairs.end(), P(l,reversed_pairs[idx2].second -1)) - pairs.begin() : M;
        if(idx < M && pairs[idx] == P(l,r) && idx +1 < M && pairs[idx+1] == P(l,r)) cout << "Yes" << endl;
        else if(idx < M && pairs[idx].second <= r && idx2 < M && reversed_pairs[idx2].first == r && pairs[idx].first == l && (reversed_pairs[idx2] != P{pairs[idx].second, pairs[idx].first})) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}