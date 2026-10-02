#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int N, total;
    int ten_count = 0;
    int five_count= 0;
    cin >> N >> total;
    if((total < N*1000) || (total > N*10000)){
        cout << -1 << " " << -1 << " " << -1 << endl;
        return 0;
    }

    total /= 1000;
    ten_count = total/10;
    total -= (10*ten_count);
    five_count = total/5;
    total -= (5*five_count);

    
    while (true) {
    int metric = N- five_count - ten_count - total;
    if ((metric == 0) && (ten_count >= 0) && (five_count >= 0) && (total >= 0)){
        cout << ten_count << " " << five_count << " " << total << endl;
        return 0;
    }
    else if (metric > 0){
        if ((metric % 4 == 0) && (five_count >= metric/4)){
            five_count -= metric/4;
            total += 5 * (metric/4);
        }
        else if((metric % 9 ==0) && (ten_count >= metric/9)){
            ten_count -= metric/9;
            total += 10 * metric/9;
        }
        else{
            ten_count -= 1;
            five_count += 2;
        }
    }
    else{
        cout << -1 << " " << -1 << " " << -1 << endl;
        return 0;
    }
    }  

}