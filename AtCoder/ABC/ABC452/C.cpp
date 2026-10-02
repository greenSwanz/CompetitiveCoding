#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,c,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main() {
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];
    ll M; cin >> M; vector<string> S(M);
    rep(i,M) cin >> S[i];
    map<char, set<ll>> m;
    rep(i,M) {
        rep(j,N) {
            if (A[j] == S[i].length()) {
                m[S[i][B[j]-1]].insert(j+1);
            }
        }
    }
    rep(i,M) {
        bool flag = ((ll)S[i].length() == N);
        rep(j, S[i].length()) {
            if (m[S[i][j]].find(j + 1) == m[S[i][j]].end()) {
                flag = false; break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
}