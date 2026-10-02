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
        set<char> letters;
        map<char,ll> m;
        string s;
        cin >> s;
        rep(i,s.length()){
            letters.insert(s[i]);
        }
        vector<char> letters_v(letters.begin(), letters.end());
        rep(i,letters_v.size()){
            m.insert({letters_v[i],0});
        }

        rep(i,s.length()){
            m[s[i]]++;
        }
        string str = "";
        priority_queue<pair<ll,char>> qu;
        rep(i,letters_v.size()){
            qu.push({m[letters_v[i]], letters_v[i]});
        }
        if(qu.top().first > ((ll)s.length() + 1) / 2){ 
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
            while(str.length() != s.length()){
                auto top = qu.top();
                qu.pop();
                if(!str.empty() && str.back() == top.second){
                    auto second = qu.top();
                    qu.pop();
                    str += second.second;
                    second.first--;
                    if(second.first > 0) qu.push(second);
                    qu.push(top); 
                }
                else{
                    str += top.second;
                    top.first--;
                    if(top.first > 0) qu.push(top);
                }
            }
            cout << str << endl;
        }
    }
}
