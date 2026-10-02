#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main() {
    set<string> A = {"a", "b", "c"};
    set<string> D = {"d", "e", "f"};
    set<string> G = {"g", "h", "i"};
    set<string> J = {"j", "k", "l"};
    set<string> M = {"m", "n", "o"};
    set<string> P = {"p", "q", "r", "s"};
    set<string> T = {"t", "u", "v"};
    set<string> W = {"w", "x", "y", "z"};

    map<set<string>, int> score = {
        {A, 2}, {D, 3}, {G, 4}, {J, 5},
        {M, 6}, {P, 7}, {T, 8}, {W, 9}
    };

    vector<set<string>> s = {A, D, G, J, M, P, T, W};

    int N;
    cin >> N;

    rep(i, N) {
        string str;
        cin >> str;

        string ch(1, str[0]);

        rep(j, 8) {
            if (s[j].find(ch) != s[j].end()) {
                cout << score[s[j]];
            }
        }
    }

    return 0;
}