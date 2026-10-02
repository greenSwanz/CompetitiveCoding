#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    ll anss = 1LL<<30;
    ll ans[N];
    rep(i,N)ans[i]=0;
    rep(i,N){
        while((A[i]%2)==0){
            A[i]/=2;
            ans[i]++;
        }
    }
    rep(i,N)anss=min(anss,ans[i]);
    cout << anss << endl;
}