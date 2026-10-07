#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t; cin >> t;
    rep(_,t){
        ll n; cin >> n;
        stack<ll> s;
        map<ll,bool> m;
        string st; 
        cin >> st;
        repp(i,1,n+1){
            char temp = st[i-1];
            if(temp == '1'){
                s.push(i);
            }
            else if(temp == '2'){
                if(!s.empty()) {m[s.top()] = true; s.pop();}
                else m[i] = true;
            }
            else{
                m[i] = true;
            }
        }
        ll np = 0;
        repp(i,1,n+1){
            if(!m[i]) np++;
        }
        cout << np << endl;
        repp(i,1,n+1){
            if(!m[i]) cout << i << " ";
        }
        cout << endl;

    }
}