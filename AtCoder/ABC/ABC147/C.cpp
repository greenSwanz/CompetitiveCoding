#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    int testimonies[N][N];
    rep(i,N)rep(j,N)testimonies[i][j] = 2;

    ll A;
    ll x;
    ll y;
    rep(i,N){
        cin >> A;
        rep(j,A){
            cin >> x >> y;
            testimonies[i][x-1] = y;
        }
    }
    ll m = 0;
    rep(bit, 1<<N){
        bool valid = true;
        bool invalid = false;
        bool invalid_two = true;
        vector<ll> grp;
        vector<ll> non_grp;
        rep(i,N){
            if(bit & 1<<i){
                grp.push_back(i);
            }
            else{
                non_grp.push_back(i);
            }
        }
        for(ll i : grp){
            for(ll j : grp){
                if(i==j) continue;
                if((testimonies[i][j] == 0)){
                    valid = false;
                }
            }
        }
        for(ll i : grp){
            for(ll j : non_grp){
                if(i==j) continue;
                if((testimonies[i][j] == 1)){
                    valid = false;
                }
            }
        }
        for(ll i : non_grp){
            for(ll j : non_grp){
                if(i==j) continue;
                if((testimonies[i][j] == 1)){
                    invalid = true;
                }
            }
            for(ll j : grp){
                if(i==j) continue;
                if((testimonies[i][j] == 0)){
                    invalid = true;
                }
            }
            if(!invalid){
                invalid_two = false;
            }
            invalid = false;
        }

        if(valid && invalid_two) m = max(m,(ll)grp.size());
    }
    cout << m << endl;
}