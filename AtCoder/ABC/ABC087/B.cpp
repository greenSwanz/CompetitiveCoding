#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int A; //500 = 50 *10
    cin >> A;
    int B; //100 = 50 * 2
    cin >> B; 
    int C; //50 = 50*1
    cin >> C;
    int total;
    cin >> total;

    int factor = total /50;
    if((10*A + 2*B + C)< factor){
        cout << 0 << endl;
        return 0;
    }
    int counter  = 0;
    for(int i = 0; i < A +1; i++){
        for(int j = 0; j <B+1; j++){
            for(int k = 0; k < C+1; k++){
                if ((500*i + 100*j + 50*k) == total){
                    counter ++;
                }
            }
        }
    }

    cout << counter << endl;    

}