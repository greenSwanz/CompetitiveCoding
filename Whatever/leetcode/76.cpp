#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string s,t; cin >> s >> t; ll lent = t.length();
    unordered_map<char,ll> mt; rep(i,lent) mt[t[i]]++;
    unordered_map<char,ll> st; ll total = 0; ll left = 0; ll min_len = LLONG_MAX; ll bestleft = 0;
    rep(right,s.length()){
        if(mt.count(s[right]) && st[s[right]] < mt[s[right]]) total++; st[s[right]]++;
        while(total == lent){
            if(right - left + 1 < min_len){ min_len = right-left + 1; bestleft = left;}
            if(mt.count(s[left]) && st[s[left]]-- == mt[s[left]]) --total; left++;
        }
    }
    cout << ((min_len == LLONG_MAX) ? "" : s.substr(bestleft,min_len)) << endl;
}