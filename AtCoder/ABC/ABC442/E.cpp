#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Q;
    cin >> N >> Q;
    P coords[N];
    ll squaresums[N];
    ll gradients[N];
    vector<ll> gradients_sorted;
    gradients_sorted.resize(N);


    ll temp;
    ll temp2;
    rep(i,N){
        //under the lines and in the circles
        cin >> coords[i].first >> coords[i].second;
        //squaresums[i] = pow((coords[i].first),2) + pow((coords[i].second),2);
        if(coords[i].second == 0){
            gradients[i] = 0;
            gradients_sorted[i] = 0;
        }
        else{
        gradients[i] = ((coords[i].second)/(coords[i].first));
        gradients_sorted[i] = gradients[i];
    }}

    sort(gradients_sorted.begin(), gradients_sorted.end());

    ll A;
    ll B;
    //ll temp;
    rep(i,Q){
        cin >> A >> B;
        auto it = lower_bound(gradients_sorted.begin(), gradients_sorted.end(), gradients[A-1]);
        auto it2 = lower_bound(gradients_sorted.begin(),gradients_sorted.end(), gradients[B-1]);

        cout << ((it - N) - (it2 - N)) << endl;

    }
}