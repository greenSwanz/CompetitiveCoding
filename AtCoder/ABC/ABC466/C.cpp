#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N; cin >> N;
    ll left = 1; ll right = 2; 
    ll total = 0;
    while(right <= N && left <= N){
        string temp;
        cout << "? " << left << " " << right << endl;
        cin >> temp;
        if(temp == "Yes") right++;
        else{
            total += right - left - 1;
            left++;
            if(left == right) right++;
        }
    }
    total += (N - left) * (N - left + 1) / 2;
    cout << "! " << total << endl;
}