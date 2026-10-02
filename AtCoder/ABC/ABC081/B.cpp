#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0; i<n; i++){
        cin >> A[i];
        if(A[i]%2 ==1){
            cout << 0 <<endl;
            return 0;
        }
    }
    int temp = 0;
    while (true){
        for(int i=0; i<n; i++){
            if (A[i]%2 ==1){
                cout << temp <<endl;
                return 0;
            }
            else{
                A[i] /= 2;
            }
            
        }
        temp ++;
    }
}