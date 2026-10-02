#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string s;
    cin >> s;
    int temp = 0;
    for (int i = 0; i<3; i++) {
        if(s[i] == '1'){
            temp ++;
        }
    }
    cout << temp;
}