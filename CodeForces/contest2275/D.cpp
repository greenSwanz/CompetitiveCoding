#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t; cin >> t;
    rep(_,t){
        ll k,n; cin >> n >> k;
        set<ll> imp; vector<vector<ll>> s;
        rep(i,n){
            ll a,b,c; cin >> a >> b >> c;
            if(a==b && b == c && a == c){
                imp.insert(a+b+c);
            }
            else{
                s.push_back({a+b+c,a,b,c});
            }
        }
        if(!imp.empty()){
            cout << *imp.begin() << endl; continue;
        }
        sort(s.begin(),s.end()); 
        ll lo = 0, hi = LLONG_MAX;
        while(hi > lo){
            ll mid = (hi + lo)/2;
            ll temp = k;
            ll temp2 = s[0][0];
            ll index = 0;
            bool codition;
            while(temp >0){
                ll a = s[index][1], b = s[index][2], c= s[index][3];
                ll m = max(c, max(a,b));
                if (m != a){
                    temp -= min(min(abs(a-c), abs(b-c)),abs(a-b)); temp--;
                }
                temp--;
                
            }
        }
        
    }
}