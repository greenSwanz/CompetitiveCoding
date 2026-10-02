#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int N, t_current, x_current, y_current;
    cin >> N;
    bool possible = true;

    int t_prev = 0, x_prev = 0, y_prev = 0;
    for(int i = 0; i < N; i++){
        cin >> t_current >> x_current >> y_current;
        int delta_xy = abs((x_current - x_prev) + (y_current - y_prev));
        int delta_ts = abs((t_current - t_prev));
        if (delta_xy < delta_ts){
            if ((delta_ts + delta_xy) % 2 != 0) {
                possible = false;
            } 
        }
        if(delta_xy > delta_ts){
            possible = false;
        }
        t_prev = t_current;
        x_prev = x_current;
        y_prev = y_current;
    }
    if (possible){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
    
}