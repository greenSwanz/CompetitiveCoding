#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<char> S(N);
    deque<ll> A;
    bool end = true;
    rep(i,N){
        cin >> S[i];
    }
    rep(i,N){
        if(end) A.push_back(i+1);
        else A.push_front(i+1);
        if(S[i] == 'o') end = !end;
    }

    if(end){
        rep(i,N){
            cout << A[i] << " ";
        }
    }
    else{
        rep(i,N){
            cout << A[N-i-1] << " ";
        }
    }
}