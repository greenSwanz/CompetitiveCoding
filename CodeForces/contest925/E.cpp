#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t; cin >> t;
    rep(_,t){
        ll n,m; cin >> n >> m;
        vector<ll> a(n);    
        map<ll,ll> end_zeroes; //end_zeros[i]= how many number have leading ending of i
        rep(i,n){
            cin >> a[i];
        }
        ll total_digits = 0;
        rep(i,n){
            ll d = 10; total_digits++;
            while(a[i] / d > 0) {d*= 10; total_digits++;}
            ll no_end_zeroes = 0; d = 10;
            while(a[i] % d == 0) {
                no_end_zeroes++; 
                d*= 10;  
            }
            end_zeroes[no_end_zeroes]++;
        }
        if(total_digits <= m){
           cout << "Anna" << endl; continue;
        }
        ll turn = 0;
        while((n > 1 || !turn) && !end_zeroes.empty()){
            ll temp = (*(--end_zeroes.end())).first;
            if(!turn){total_digits-=temp;}
            if(turn) n--;
            end_zeroes[temp]--;
            if(end_zeroes[temp]==0){
                end_zeroes.erase(temp);
            }
            turn = (turn == 0) ? 1 : 0;       
        }
        cout << ((total_digits <= m) ? "Anna" : "Sasha") << endl;

    }
}