#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string s,t;
    cin >> s; cin >> t; 
    queue<char> q;
    rep(i,s.length()) q.push(s[i]);
    ll total = 0;
    rep(i,t.length()){
        if(!q.empty() && q.front() == t[i]){q.pop(); continue;}
        if(t[i] == 'A') {total++; continue;}
        ll temp = 0;
        while(!q.empty() && q.front() == 'A'){q.pop(); temp++;}
        if(q.empty() || q.front() != t[i]) {cout << -1 << endl; return 0;}
        q.pop(); total+= temp;
    }
    while(!q.empty()){
        if(q.front() != 'A') {cout << -1 << endl; return 0;}
        q.pop(); total++;
    }
    cout << total << endl;
}