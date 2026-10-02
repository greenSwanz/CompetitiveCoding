#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,D;

    cin >> N >> D;
    int squareD = pow(D,2);

    P A[N];
    rep(i,N){
        cin >> A[i].first >> A[i].second;
    }

    string visited[N];
    queue<int> q;
    q.push(0);

    int temp;
    visited[0] = "Yes";

    while (!q.empty()){
        temp = q.front();       
        rep(i,N){
            if (((pow(((A[temp].first) - (A[i].first)),2) + pow(((A[temp].second) - (A[i].second)),2)) <= squareD) && (visited[i] != "Yes")){
                visited[i] = "Yes";
                q.push(i);
            }
        }
        q.pop();
    }

    rep(i,N){
     if(visited[i] == "Yes"){
        cout << "Yes" << endl;
     }   
     else{
        cout << "No" << endl;
     }
    }
}