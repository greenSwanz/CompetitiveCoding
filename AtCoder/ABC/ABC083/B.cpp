#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int N, A, B;
    cin >> N >> A >> B;
    int temp;
    int counter = 0;
    for (int i=1; i <= N; i++){
        temp =  
        (i/((int)pow(10,4))) + 
        ((i%((int)pow(10,4)))/((int)pow(10,3))) + 
        (((i%((int)pow(10,4)))%((int)pow(10,3)))/((int)pow(10,2))) +
        ((((i%((int)pow(10,4)))%((int)pow(10,3)))%((int)pow(10,2)))/10) + 
        (i%10);
        if (A <= temp && temp <= B){
            counter += i;
        }
    }
    cout << counter << endl;
}