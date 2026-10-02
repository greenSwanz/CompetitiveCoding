#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<P> height(N);

    rep(i,N){
        cin >> height[i].second >> height[i].first;
    }
    sort(height.begin(), height.end());
    for(ll i = N-2; i >= 0; --i){
        height[i].second = max(height[i].second, height[i+1].second);
    }
    ll Q;
    cin >> Q;
    ll index, temp;
    rep(i,Q){
        cin >> temp;
        index = std::lower_bound(height.begin(), height.end(), make_pair((temp+1),0LL)) - height.begin();
        cout << height[index].second << endl;
    }
}