#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll n; cin >> n;
        vector<ll> nums(n);
        rep(i,n) cin >> nums[i];
        rep(i,n){
            ll temp = nums[i];
            if((temp > 0) && (temp <= n) && (nums[temp-1] < 0)){
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        rep(i,n){
            ll temp = nums[i];
            if((temp > 0) && (temp <= n)){
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        rep(i,n) cout << nums[i] << "   " ;
        rep(i,n){ if((i +1) != nums[i]) cout << i +1 << endl;}
        cout << n+1 << endl;
};
