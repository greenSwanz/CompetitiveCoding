#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    
    vector<vector<ll>> A(N,vector<ll>(N));
    vector<vector<bool>> B(N,vector<bool>(N)); 
    ll shortest_dist = 0;

    rep(i,N){
        rep(j,N){
            cin >> A[i][j]; 
            B[i][j] = true;
        }
    }

    rep(i,N){
        if(A[i][i] != 0){
            cout << -1 << endl;
            return 0;
        }
    }

    rep(x,N){
        rep(y,N){
            rep(i,N){
                if(A[x][y] > A[x][i] + A[i][y]){
                    cout << -1 << endl;
                    return 0;
                }
                if((A[x][y] == (A[x][i] + A[i][y])) && (i != x) && (i != y)){
                    B[x][y] = false;
                }
            }
            if(B[x][y]) shortest_dist += A[x][y];
        }
    }
    cout << (shortest_dist/2 )<< endl;
    return 0;
}