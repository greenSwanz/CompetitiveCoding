#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T; cin >> T;
    rep(_,T){
        stack<char> s,t;
        string A,B; cin >> A >> B;
        rep(i,A.size()){
            if(A[i] == ')' && s.size() >= 3){
                char a,b,c; a = s.top(); s.pop(); b = s.top(); s.pop(); c= s.top(); s.pop();
                if(!((c == '(') &&  (a == 'x') && (b == 'x'))) { s.push(c); s.push(b); s.push(a); s.push(A[i]); }
                else {s.push('x'); s.push('x');}
            }
            else {
                s.push(A[i]);
            }
        }
        rep(i,B.size()){
            if(B[i] == ')' && t.size() >= 3){
                char a,b,c; a = t.top(); t.pop(); b = t.top(); t.pop(); c = t.top(); t.pop();
                if(!((c == '(') &&  (a == 'x') && (b == 'x'))) { t.push(c); t.push(b); t.push(a); t.push(B[i]); }
                else { t.push('x'); t.push('x'); }
            }
            else {
                t.push(B[i]);
            }
            
        }
        bool f = (s.size() == t.size());
        while (f && !s.empty()) {
            if (s.top() != t.top()) f = false;
            s.pop(); t.pop();
        }
        cout << (f ? "Yes" : "No") << endl;
    }
}