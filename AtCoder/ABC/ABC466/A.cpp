#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll count = 0;
    rep(i,N){
        ll temp; cin >> temp;
        if (temp < 0) {
            count++;
        }
    }
    if(count == N) {cout << "yes" << endl; return 0;}
    cout << "no" << endl;
}