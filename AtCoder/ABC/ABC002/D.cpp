#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    //N is number of legislators
    //M is the number of relationships
    cin >> N >> M;
    bool connections[N][N];

    ll x;
    ll y;
    rep(i,N)rep(j,N)connections[i][j]=false;
    rep(i,M){
        cin >> x >> y;
        connections[x-1][y-1] = 1;
        connections[y-1][x-1] = 1;

    }
    ll m = 0;
    rep(bit, 1<<N){
        bool valid = true;
        vector<ll> grp;
        rep(i,N){
            if(bit & (1<<i))//i-th bit is 1
            {
                grp.push_back(i);
            }
        }
        for(auto i : grp){
            for(auto j : grp){
                if(i==j)continue;
                if(!(connections[i][j])){
                    valid = false;
                }
            }
        }
        if(valid){
            m = max(m,(ll)grp.size());
        }

    }
    cout << m << endl;
    return 0;

}