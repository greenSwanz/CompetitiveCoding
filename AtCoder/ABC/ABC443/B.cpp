#include <bits/stdc++.h>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll no_of_beans = N;
    ll start = 0;
    while(no_of_beans < K){
        start ++;
        no_of_beans += (N + start);

    }
    cout << start << endl;
}