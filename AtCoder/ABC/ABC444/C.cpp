#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    
    set<ll> answers;
    rep(i,N){
        cin >> A[i];
    }
    sort(A,A + N);
    if((N % 2) == 1){
        cout << A[N-1] << endl;
        return 0;
    }

    
    bool temp = true;
    ll temp2 = A[0] + A[N-1];
    rep(i,(N/2)){
        if(!((A[i] + A[N-1 -i]) == temp2)){
            temp = false;
        }
    }
    if (temp){
        answers.insert(temp2);
    }
    temp = true;

    ll end = N-1;
    while((A[end] == A[end-1]) && (end >= 1)){
        end -= 1;
    }
    if(end > 0){
        temp2 = A[0] + A[end - 1];
        rep(i,(end/2)){
            if (!((A[i] + A[end - 1 - i]) == temp2)){
                temp = false;
            }
        }
        if(end%2==1)temp=false;
        if (temp){
            answers.insert(temp2);
        }
    }else{
        answers.insert(A[end]);
    }
    for(auto i: answers){
        cout << i << " ";
    }
}

