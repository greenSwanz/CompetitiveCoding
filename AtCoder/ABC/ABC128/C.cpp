#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;

    cin >> N >> M;

    int n;
    int switches[M][N];
    rep(i,M){
        cin >> n;
        rep(j,n){
            cin >> switches[i][j];
        }
        repp(j,n,N){
            switches[i][j] = 0;
        }
    }
    
    int p[M];
    rep(i,M){
        cin >> p[i];
    }

    int counter = 0;
    for(int bit = 0; bit < (1 << N); ++bit){
        
        
        bool temp = true;

        rep(i,M){
            int current_no = 0;
            rep(j,N){
                if (bit & (1 << switches[i][j])) {
                    current_no += 1; 
                }
            }
            if (current_no % 2 != p[i]){
                temp = false;
            }
        }

        if (temp){
            counter += 1;
            temp = false;
        }
    }

    cout << counter << endl;
}