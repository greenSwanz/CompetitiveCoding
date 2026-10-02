#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main() {
    ll T;
    cin >> T;
    rep(_,T){
        ll N;
        cin >> N;
        vector<ll> a(N);
        rep(i,N) cin >> a[i];
        vector<ll> first_index;
        vector<ll> cumsum_one(N+1);
        vector<ll> cumsum_two(N+1);
        vector<ll> cumsum_three(N+1);
        cumsum_one[0] = 0; cumsum_two[0] = 0; cumsum_three[0] = 0; 
        repp(i,1,N+1){
            cumsum_one[i] = cumsum_one[i-1]; cumsum_two[i] = cumsum_two[i-1]; cumsum_three[i] = cumsum_three[i-1];
            if(a[i-1] == 1) cumsum_one[i]++;
            else if(a[i-1] == 2) cumsum_two[i]++;
            else cumsum_three[i]++;
        }

        repp(i,1,N-1) if(cumsum_one[i] >= cumsum_two[i] + cumsum_three[i]) first_index.push_back(i);
        sort(first_index.begin(),first_index.end());
        
        vector<ll> second_index(N+1);
        rep(k,N+1) second_index[k] = cumsum_one[k] + cumsum_two[k] - cumsum_three[k];
        vector<ll> m(N+1, LLONG_MIN);
        m[N-1] = second_index[N-1];
        for(ll i=N-2; i >=0; i--) m[i] = max(second_index[i], m[i+1]);

        bool valid = false;
        rep(i, first_index.size()){
            ll index = first_index[i];
            if(m[index+1] >= second_index[index]) { valid = true; break; }
        }

        cout << (valid ? "YES" : "NO") << endl;

    }
}