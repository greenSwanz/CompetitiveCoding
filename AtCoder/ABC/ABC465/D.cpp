#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;
    cin >> T;
    rep(_,T){
        ll X,Y,K;
        cin >> X >> Y >> K;

        map<ll,ll> dist;
        ll x = X;
        ll temp = 0;
        bool flag = true;
        while(flag){
            dist[x] = temp;
            if(x==0) (flag = false);
            x /= K; 
            temp++;
        }
        if(X==Y){
            cout << 0 << endl;
            continue;
        }
        ll y  = Y;
        temp = 0;
        while(dist.find(y) == dist.end()){
            y /= K;
            temp++;
        }

        cout << temp + dist[y] << endl;

    }
}