#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int Q;
    cin >> Q;
    int temp;
    int volume = 0;
    bool playing = false;
    rep(i,Q){
        cin >> temp;

        if(temp == 1){
            volume++;
        }
        else if((temp == 2) && (volume >= 1)){
            volume--;
        }
        else if(temp == 3){
            if (!playing) {
                playing = true;
            }
            else{
                playing = false;
            }
        }

        if((volume > 2) && (playing == true)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }

    }
}