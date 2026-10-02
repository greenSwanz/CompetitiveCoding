#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int T;
    cin >> T;
    rep(_,T){
        long double X1,Y1,R1,X2,Y2,R2;
        cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
        if(abs(R1 - R2) <= sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1)) && sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1)) <= (R1 + R2)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }        

    }
}