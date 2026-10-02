#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int A;
    int B; 
    cin >> A >> B;

    cout << (A * pow(2,B)) << endl;
    return 0;
}