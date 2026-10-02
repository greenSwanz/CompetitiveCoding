#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;

    ll pow10[11];
    pow10[0] = 1;
    repp(i,1,11) pow10[i] = pow10[i-1] * 10;

    vector<vector<ll>> good_nums(11);
    ll temp = 1;
    good_nums[1].push_back(1);
    rep(i,30){
        temp *= 2;
        string s = to_string(temp);
        if (s.length() <= 10) good_nums[s.length()].push_back(temp);
    }

    vector<set<ll>> good(11);
    good[0].insert(0);
    repp(i,1,11){
        repp(j,1,i+1){
            for(ll x : good[i-j])
                for(ll y : good_nums[j])
                    good[i].insert(x * pow10[j] + y);
        }
    }

    vector<ll> big;
    repp(i,1,11)
        for(ll x : good[i]) big.push_back(x);

    cout << big[N-1] << endl;
}