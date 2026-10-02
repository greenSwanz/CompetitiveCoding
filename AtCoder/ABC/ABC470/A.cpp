#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;
    repp(i,1,N+1){
        if(i % 3 == 0) cout << "Fizz" << endl;
        else cout << i << endl;
    }
}