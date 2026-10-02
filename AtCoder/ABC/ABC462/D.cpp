#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,D;
    cin >> N >> D;
    vector<ll> time(1e6+1);
    //1000000 = 1e6
    rep(i,1e6+1){
        time[i] = 0;
    }
    ll S,T;
    rep(i,N){
        cin >> S >> T;
        if(T - D >= S){
            time[S]++;
            time[T-D+1]--;
        }
    }
    vector<ll> cumsum(1e6+1);
    cumsum[0] = time[0];
    repp(i,1,1e6+1){
        cumsum[i] = cumsum[i-1] + time[i];
    }
    ll count = 0;
    repp(i,1,1e6+1-D){
        if(cumsum[i] >= 2){
            count += cumsum[i]*(cumsum[i]-1)/2;
        }
    }
    cout << count << endl;

}