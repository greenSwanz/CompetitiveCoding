#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

bool is_good(ll temp){
    ll num1 = -1, num2 = -1;
    while(temp > 0){
        ll d = temp % 10;
        temp /= 10;
        if(d == num1 || d == num2) continue;
        if(num1 == -1) num1 = d;
        else if(num2 == -1) num2 = d;
        else return false;
    }
    return true;
}

int main(){
    ll T;
    cin >> T;

    vector<ll> good_nums;
    vector<ll> c;
    for(ll d = 1; d <= 9; ++d) c.push_back(d);

    while(!c.empty()){
        vector<ll> next;
        for(ll v : c){
            if(v >= 2) good_nums.push_back(v);
            rep(d,9){
                ll w = v*10 + d;
                if(w <= (ll)1000000000 && is_good(w))
                    next.push_back(w);
            }
        }
        c.swap(next);
    }

    unordered_map<ll,ll> cache;
    
    rep(_,T){
        ll X;
        cin >> X;
        auto it = cache.find(X);
        if(it != cache.end()){
            cout << it->second << endl;
            continue;
        }
        for(ll y : good_nums){
            if(is_good(X * y)){
                cache[X] = y;
                cout << y << endl;
                break;
            }
        }
    }
}