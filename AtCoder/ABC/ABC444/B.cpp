#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N, K;
    cin >> N >> K;
    ll counter = 0;
    repp(i,1,N+1){
        ll temp = i;
        ll temp2 = 0;
        while(temp > 0){
            temp2 += temp % 10;
            temp /= 10;
        }
        if (temp2 == K){
            counter ++;
        }
    }
    cout << counter << endl;
}