#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    priority_queue<ll> pq;
    ll Q,V; cin >> Q >> V;
    ll time = 0;
    rep(i,Q){
        ll inst; cin >> inst; ll t,w;
        cin >> t;
        if(inst == 1) {
            cin >> w;
            pq.push(w-t);
        }
        else{
            if(pq.empty()) cout << -1 << endl;
            else{
                ll temp = pq.top() + t;
                cout << min(temp,V) << endl;
                pq.pop();
            }
        }
    }
}