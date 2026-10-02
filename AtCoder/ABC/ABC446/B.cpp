#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    bool A[M];
    rep(i,M){
        A[i] = false;
    }
    rep(i,N){
        
        ll num;
        cin >> num;
        bool done = false;
        rep(j,num){            
            int temp;
            cin >> temp;
            if ((A[temp -1] == false) && (!done)){
                A[temp - 1] = true;
                cout << temp << endl;
                done = true;
            }
        }
        if (!done){
                cout << 0 << endl;
        }
        done = false;
    }
}