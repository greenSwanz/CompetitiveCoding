#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int counter = 0;
    string inp;
    cin >> inp;
    rep(i,inp.size()){
        if((inp[i] == 'i') || (inp[i] == 'j')){
            counter++;
        }
    }

    cout << counter << endl;
}