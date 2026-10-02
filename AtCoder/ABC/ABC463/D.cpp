#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<P> cloths(N);
    // put R,L
    rep(i,N) cin >> cloths[i].second >> cloths[i].first;
    sort(cloths.begin(), cloths.end());
    //check invalid
    ll temp = cloths[0].first;
    ll total = 1;
    repp(i,1,N){
        if (cloths[i].second > temp) {
            total++; temp = cloths[i].first;
        }
    }
    if (total < K) {
        cout << -1 << endl; return 0;
    }
    //find maximum
    ll low = 0, high = 1000000000;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll temp = cloths[0].first;
        ll total = 1;
        repp(i,1,N){
            if (cloths[i].second > temp + mid) {
                total++; temp = cloths[i].first;
            }
        }
        if (total >= K) low = mid + 1;
        else high = mid - 1;
    }

    cout << low << endl;
}

    
