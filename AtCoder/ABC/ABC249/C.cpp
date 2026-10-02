#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int N,K;

    cin >> N >> K;
    string words[N];
    rep(i,N){
        cin >> words[i];
    }

    int counter = 0;
    for(int bit = 0; bit < (1 << N); ++bit){
        int current_total = 0;
        int A[26];
        rep(i,26){
            A[i] = 0;
        }
            for (int i = 0; i < N; ++i) {
                if (bit & (1 << i)) {

                    for (char j : words[i]){
                        A[(j - 'a')] += 1;
                    }
                }

            }
            rep(i,26){
                if (A[i] == K){
                    current_total += 1;
                }
            }

            if(current_total > counter){
                counter = current_total;
            }
    }

    cout << counter << endl;

}