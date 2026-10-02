#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T; cin >> T;
    ll a,b,x;
    rep(_,T){
        cin >> a >> b >> x;
        vector<ll>div_max;
        vector<ll>div_max_diff;
        div_max.push_back(0);
        div_max_diff.push_back(abs(a-b));
        div_max.push_back(max(a,b)/x);
        div_max_diff.push_back(min(a,b));
        repp(i,2,64){
            div_max.push_back(max(div_max[i-1], div_max_diff[i-1])/x);
            div_max_diff.push_back(min(div_max[i-1], div_max_diff[i-1]));
        }
        vector<ll> differences;
        rep(i,64){
            differences.push_back(abs(div_max[i] - div_max_diff[i]) + i);
        }
        sort(differences.begin(), differences.end());
        cout << differences[0] << endl;
    }
}