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
        ll N,D;
        cin >> N >> D;
        queue<P> q;
        ll A[N];
        ll B[N];
        rep(i,N){
            cin >> A[i];
        }
        rep(i,N){
            cin >> B[i];
        }
        rep(i,N){
            q.push({A[i],i});
            while(!(q.empty()) && q.front().first <= B[i]){
                B[i] -= q.front().first;
                q.pop();
            }
            if(B[i])q.front().first -= B[i];
            if(!(q.empty())&&(q.front().second + D) <= i){
                q.pop();
            }
        }
        ll total = 0;
        while(!(q.empty())){
            total += q.front().first;
            q.pop();
        }

        cout << total << endl;
            
    }
}