#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
  map<ll,ll> nom;
  ll N; cin >> N; ll A[N]; rep(i,N) {cin >> A[i]; nom[(A[i])]++;} ll total = 0;
  for(auto i : nom) if(i.second % 2 != 0) total+= i.first;
  cout << total << endl;
}