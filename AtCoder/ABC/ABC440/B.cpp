#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); ++i)

int main() {
    int N;
    if (!(cin >> N)) return 0; 

    vector<int> A(N); 
    rep(i, N) {
        cin >> A[i];
    }

    vector<pair<int, int>> pairs(N);
    rep(i, N) {
        pairs[i] = {A[i], i + 1}; 
    }

    sort(pairs.begin(), pairs.end());

  
    rep(i, min(N, 3)) {
         cout << pairs[i].second << (i == min(N, 3) - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
