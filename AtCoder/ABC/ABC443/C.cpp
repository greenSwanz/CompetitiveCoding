#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N, T;
    cin >> N >> T;
    vector<ll> A;
    A.resize(N);
    ll time_closed = 0;
    ll current_time_of_closure = 0;
    if (N > 0){
        cin >> A[0];
        current_time_of_closure = A[0];
        if (T - A[0] < 100){
            time_closed = (T - A[0]);
        }
        else{
            time_closed = 100;
        }
    }
    repp(i,1,N){
        cin >> A[i];
        if ((A[i] - current_time_of_closure) >= 100){
            if (T - A[i] < 100){
                time_closed += (T - A[i]);
            }
            else{
                time_closed += 100;
            }
            current_time_of_closure = A[i];
        }
    }
    cout << (T - time_closed) << endl;
}