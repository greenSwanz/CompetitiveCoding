#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
//Vshaped sequences

struct Fenwick {
    int n;
    vector<ll> t;
    Fenwick(int n) : n(n), t(n + 1, 0) {}

    void update(int i, ll delta) {
        for (; i <= n; i += i & -i)
            t[i] += delta;
    }

    ll query(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += t[i];
        return s;
    }
};

int main(){
    ll T; cin >> T;
    rep(_,T){
        ll N; cin >> N; vector<P> points(N); 
        set<ll> second_coord;
        rep(i,N) {
            cin >> points[i].first >> points[i].second;
            second_coord.insert(points[i].second);
        }
        sort(points.begin(), points.end());
        vector<ll> sc(second_coord.begin(), second_coord.end());
        Fenwick t(sc.size()); vector<ll> L(N,0);
        for(ll i = 0;  i<N;){
            ll j = i;
            while( j < N && points[j].first == points[i].first ) ++j;
            repp(k,i,j){
                ll lidx = lower_bound(sc.begin(), sc.end(), points[k].second) - sc.begin();
                L[k]+= i - t.query(lidx+1);
            }
            repp(k,i,j){
                ll lidx = lower_bound(sc.begin(), sc.end(), points[k].second) - sc.begin();
                t.update(lidx+1, 1);
            }
            i=j;
        }
        t = Fenwick(sc.size()); vector<ll> R(N,0);
        for(ll i = 0;  i<N;){
            ll j = i;
            while( j < N && points[N-1-j].first == points[N-1-i].first ) ++j;
            repp(k,i,j){
                ll lidx = lower_bound(sc.begin(), sc.end(), points[N-1-k].second) - sc.begin();
                R[N-k-1] += i - t.query(lidx+1);
            }
            repp(k,i,j){
                ll lidx = lower_bound(sc.begin(), sc.end(), points[N-1-k].second) - sc.begin();
                t.update(lidx+1, 1);
            }
            i=j;
        }
        ll total = 0;
        rep(i,N) total += L[i]*R[i];
        cout << total << endl;
    }
    return 0;
}