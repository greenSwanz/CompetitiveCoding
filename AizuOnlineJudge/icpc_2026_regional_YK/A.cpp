#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,c,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll N = -1; 
    cin >> N;
    while(N != 0){
        vector<int> A(N);
        rep(i,N){
            cin >> A[i];
            if(A[i] <= 2) A[i]+=13;
        }
        sort(A.begin(),A.end());
        cout << ((A[N-1] < 14) ? A[N-1] : (A[N-1] - 13)) << endl;
        cin >> N;
    }
    return 0;   
}