#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T; cin >> T;
    rep(_,T){
        ll N; cin >> N; ll total_books = 0; ll cur_index = 0; ll n;
        rep(i,N){ 
            ll type; cin >> type;
            if(type == 1){
                cin >> n;
                total_books = max(cur_index+n,total_books);
                cur_index += n;
            }
            else{ cur_index = max(0LL,cur_index - n);}
        }
        cout << total_books << endl;
    }
}