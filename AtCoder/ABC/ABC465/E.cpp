#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
const ll p = 998244353;

int main(){
    string N; cin >> N;
    ll n = N.size();
    vector<vector<vector<vector<vector<ll>>>>> dp(n + 1,
    vector<vector<vector<vector<ll>>>>(2,
    vector<vector<vector<ll>>>(2,
    vector<vector<ll>>(3,
    vector<ll>(1 << 10)))));
    rep(i,n+1) rep(smaller,2) rep(j,2) rep(k,3) rep(l,1024) dp[i][smaller][j][k][l] = 0;
    dp[0][0][0][0][0] = 1;
    rep(i,n){
        rep(smaller,2){
            rep(j,2){
                rep(k,3){
                    rep(l,1024){
                        rep(x, smaller ? 10 : (int) (N[i] - '0') +1){
                            dp[i+1][smaller || x < (int) (N[i] - '0')][j || x == 3][(k + x) % 3][(l == 0 && x == 0) ? 0 : (l | (1 << x))] 
                            =  (dp[i+1][smaller || x < (int) (N[i] - '0')][j || x == 3][(k + x) % 3][(l == 0 && x == 0) ? 0 : (l | (1 << x))]  +
                            dp[i][smaller][j][k][l] )% p;
                        }
                    }
                }
            }
        }
    }
    ll total = 0;
    rep(smaller,2){
        rep(j,2){
            rep(k,3){
                rep(l,1024){
                    ll semi = 0;
                    rep(m,10){
                        if((1 << m) & l) semi++;
                    }
                    if((j == 1 && (k != 0) && (semi != 3)) ||
                        (j != 1 && (k == 0) && (semi != 3)) ||
                        (j != 1 && (k != 0) && (semi == 3))) total = (total + dp[n][smaller][j][k][l]) % p;
                }
            }
        }
    }
    cout << (total -1) % p << endl;
}