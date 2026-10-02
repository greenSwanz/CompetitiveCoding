#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int N;
vector<P> height_S;

bool satisfiable(ll x){
    bool tempBool = true;
    vector<ll> tempList;
    rep(i,N){
        if (x < height_S[i].first){
            return false;
        }
        ll temp = ((x - height_S[i].first)/(height_S[i].second));
        tempList.push_back(temp);        
    }
    sort(tempList.begin(), tempList.end());
    rep(i,N){
        if((tempList[i]) < i){
            tempBool = false; break;
        }
    }
    return tempBool;
}



int main(){
    
    cin >> N;
    height_S.resize(N);

    rep(i,N) {
        cin >> height_S[i].first >> height_S[i].second;
    }


    ll right = 1LL<<51;
    ll left = 0;
    ll mid = (right+left)/2;

    while (mid != right) {
        if (satisfiable(mid)){
            right = mid;
            mid = (right + left)/2;
        }
        else
        {
            left = mid + 1;
            mid = (right + left)/2;
        }
    }   

    cout << mid << endl;




}