#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N, Q;
    cin >> N >> Q;

    int A[N];
    int B[N];
    cin >> A[0];
    B[0] = A[0];
    repp(i,1,N){
        cin >> A[i];
        B[i] = A[i];
        A[i] += A[i-1];
    }
    ll instruction;
    ll x;
    ll l;
    ll r;
    ll temp;
    ll temp2;
    rep(i,Q){
        cin >> instruction;
        if(instruction == 1){
            cin >> x;
            temp = B[x-1];
            temp2 = B[x];
            A[x-1] = A[x-1] - temp + temp2;
            B[x] = temp;
            B[x-1] = temp2;
        }
        else if(instruction == 2){
            cin >> l >> r;
            if(l >= 2){
                cout << (A[r-1] - A[l-2]) << endl;
            }
            else{
                cout << A[r-1] << endl;
            }
        }
    }
}