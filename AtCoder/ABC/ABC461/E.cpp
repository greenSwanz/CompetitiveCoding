#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

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
    ll N, Q;
    cin >> N >> Q;

    Fenwick brow(Q + 2), bcol(Q + 2); // make a fenwick tree of timestamps
    brow.update(1, N); // put all N in the 0th time column and row
    bcol.update(1, N); 

    vector<ll> rowTime(N + 1, 0), colTime(N + 1, 0); // initialise all row and column timestamps to 0
    ll black = 0; 

    rep(t, Q) {
        ll T, I;
        cin >> T >> I;
        ll ts = t + 1; //timestamp index for rowTime, colTime
        if (T == 1) {
            ll old = rowTime[I]; //get the last time the row was updated
            black += N - bcol.query(old); // bcol.query(old) find all columns with white stamp less than the black stamp time of rowtime[I]
            brow.update(old + 1, -1);
            brow.update(ts + 1, +1);
            rowTime[I] = ts;
        } else {
            ll old = colTime[I];
            black -= brow.query(Q + 1) - brow.query(old + 1);
            bcol.update(old + 1, -1);
            bcol.update(ts + 1, +1);
            colTime[I] = ts;
        }
        cout << black << endl;
    }
}

/* TO MEMORISE
struct Fenwick {
    int n;
    vector<long long> t;
    Fenwick(int n) : n(n), t(n + 1, 0) {}

    void update(int i, long long v) {           // point update
        for (; i <= n; i += i & -i) t[i] += v;
    }
    long long query(int i) {                    // prefix sum [1..i]
        long long s = 0;
        for (; i > 0; i -= i & -i) s += t[i];
        return s;
    }
    long long range(int l, int r) {             // [l..r]
        return query(r) - query(l - 1);
    }
    int kth(long long k) {                      // smallest i with prefix sum >= k
        int pos = 0;
        for (int pw = 1 << __lg(n); pw; pw >>= 1)
            if (pos + pw <= n && t[pos + pw] < k) { pos += pw; k -= t[pos]; }
        return pos + 1;
    }
};*/