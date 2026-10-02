#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; vector<ll> A(N); rep(i,N) {cin >> A[i];} sort(A.begin(),A.end());
    vector<ll> nums(N+1); rep(i,N){nums[N-i] = A[i] - ((i != 0) ? A[i-1] : 0);} 
    vector<ll> d; rep(i,N) rep(j, nums[N-i]) d.push_back(N-i);
    d.resize(A[N-1] + 10, 0);
    rep(k, (ll)d.size() - 1) {
        d[k+1] += d[k] / 10;
        d[k] %= 10;
    }
    while (d.size() > 1 && d.back() == 0) d.pop_back();
    string s;
    for (ll k = (ll)d.size() - 1; k >= 0; --k) s += char('0' + d[k]);
    cout << s << endl;
}       