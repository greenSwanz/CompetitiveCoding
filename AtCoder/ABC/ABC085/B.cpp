#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    int N;
    cin >> N;
    vector<int> A;
    bool different = true ;
    int x;
    for(int i=0; i<N; i++){
        cin >> x;
        for (int j=0; j<(A.size()); j++){
            if (x == A[j]){
                different = false;
            }
        }
        if (different){
            A.push_back(x);
        }
        different = true;
    }
 
    cout << A.size() << endl;
    return 0;
}

