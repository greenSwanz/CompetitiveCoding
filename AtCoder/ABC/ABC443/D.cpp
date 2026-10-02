#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    vector<ll> A;
    ll temp;
    ll counter = 0;
    ll N;
    rep(_,T){
        cin >> N;
        A.resize(N);
        
        cin >> A[0] >> A[1];
        temp = abs(A[1] - A[0]);
        counter = 0;
        repp(i,2,N){
            cin >> A[i];
            if(abs(A[i] - A[i-1]) > 1){
                temp = (A[i] - min(abs(A[i-1] + temp), abs(A[i-1] - temp)));
            }
            counter += temp;
            cout << temp << endl;
            //cout << counter << endl;
        }
        cout << (counter - 1) << endl;
        
        rep(i,N){
            cin >> A[i];
        }

    }
}