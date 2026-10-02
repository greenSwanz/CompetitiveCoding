#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string s; cin >> s;
    set<ll> a,b,c;
    rep(i,s.length()){
        if(s[i] == 'A') a.insert(i);
        if(s[i] == 'B') b.insert(i);
        if(s[i] == 'C') c.insert(i);
    }
    ll total = 0;
    auto cura = a.lower_bound(0);
    while(cura != a.end()){
        auto curb = b.lower_bound(*cura);
        if(curb == b.end()) break;
        auto curc = c.lower_bound(*curb);
        b.erase(curb);
        if(curc == c.end()) break;
        c.erase(curc);
        total++;
        cura = a.upper_bound(*cura);
    }
    cout << total << endl;

}