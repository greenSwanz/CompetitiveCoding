#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string s,t; cin >> s >> t; ll ts = t.length(); ll ss = s.length();
    map<char,set<ll>> mt;
    rep(i,ss) mt[s[i]].insert(i); ll total = 0;
    ll prev = -1;
    for(auto i : mt[t[0]]){
        ll left = i; ll index = 1; ll right = left;
        while(index < ts){
            char cur = t[index];
            auto temp = mt[cur].upper_bound(right);
            if(temp == mt[cur].end()) break;
            right = *temp;
            index++;
        }
        if(index == ts ){
            total += (left - prev) * (ss - right);
        }
        prev = left;
    }
    cout << (ss*(ss+1)/2 - total) << endl;
}





    /*
    string s,t; cin >> s >> t; ll ts = t.length(); ll ss = s.length();
    map<char,ll> mt; rep(i,ts) mt[t[i]]++;
    map<char,ll> ms; ll total = 0;
    ll right = -1; ll gt = 0;
    vector<ll> p(ss);
    rep(i,ss){
        while(total < ts && right + 1 < ss){
            right++;
            if(mt.count(s[right]) && ms[s[right]] < mt[s[right]]){
                ms[s[right]]++; total++;
            }
        }
        if(total < ts){
            gt += ss - i;
        } else {
            p[i] = right; gt += right - i;
        }
        if(mt.count(s[i]) && ms[s[i]] > 0 && right >= i) { ms[s[i]]--; total--; }
    }
    cout << gt << endl;
}
    */
