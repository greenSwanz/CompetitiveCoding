#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N; vector<ll> A(N); vector<P> p(N);
    rep(i,N) {
        cin >> A[i]; p[i].first = A[i]; p[i].second = i;
    }
    vector<ll> s;
    rep(i,3) s.push_back(A[i]);
    sort(s.begin(),s.end());
    cout << s[0] << endl;
    repp(i,3,N){
        if(A[i] > s[0]) s[0] = A[i]; sort(s.begin(),s.end());
        cout << s[0] << endl;
    }
}