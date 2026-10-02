#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T; cin >> T;
    rep(_,T){
        ll PX,PY,QX,QY,RX,RY,SX,SY; 
        cin >> PX >> PY >> QX >> QY >> RX >> RY >> SX >> SY;
        if((RX - SX)*(PY-QY) == (PX - QX)*(RY-SY)) { 
            if(((QX-PX)*(RX+SX-PX-QX) + (QY-PY)*(RY+SY-PY-QY) != 0)){
                cout << "No" << endl; continue; 
            }
        } 
        cout << "Yes" << endl;
    }
}