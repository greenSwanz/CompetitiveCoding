#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;
    string s; cin >> s; vector<ll> cumsum_hit(N+1,0);
    repp(i,1,N+1) {cumsum_hit[i] = cumsum_hit[i-1] + (s[i-1] == 'o');}
    ll pos = 1;
    repp(k,1,N+1){
        pos = max(pos,k);
        while(pos < N && cumsum_hit[pos] > pos-k) pos++;
        cout<< pos<< endl;
    }
}