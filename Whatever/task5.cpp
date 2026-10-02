#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

vector<int> f_eff(vector<int> A, vector<int> B){
    vector<int> b;
    bool done = false;
    rep(i,B.size()){
        if (!done){
            if(B[i] == 0){
                b.push_back(0);
            }
            else{
                b.push_back(B[i] -1);
                done = true;
            }
        }
        else{
            b.push_back(B[i]);

        }
    }
    return b;
}

vector<int> f(vector<int> A, vector<int> B){
    vector<int> a = successor(A);
    vector<int> temp = tritwise_min(A,a);

    while(leq(a, B) == false){
        a = successor(a);
        temp = tritwise_min(temp,a);
    }

    return temp;
}

vector<int> tritwise_min(vector<int> A, vector<int> B){
    int iter = min(A.size(), B.size());
    vector<int> r;
    rep(i,iter){
        r.push_back(min(A[i],B[i]));
    }
    return r;
}

vector<int> successor(vector<int> t){
    vector<int> r;
    bool carry = false;
    if(t[0] == 2){
        carry = true;
        r.push_back(0);
    }
    else{
        r.push_back(t[0] + 1);
    }
    repp(i,1,t.size()){
        if(carry = true){
        if(t[i] == 2){
            carry = true;
            r.push_back(0);
        }
        else{
            r.push_back(t[i] + 1);
        }
        }
        else{
           r.push_back(t[i]);
        }
    }

    return r;

}

bool leq(vector<int> A, vector<int> B){

    int iter = min(A.size(), B.size());
    bool temp = false;
    rep(i,iter){
        if(A[iter - 1 - i] <= B[iter - 1 - i]){
            temp = true;
        }
        else{
            temp = false;
            if(B.size() > A.size()){
                rep(i,B.size() - iter){
                    if(B[i] > 0){
                        temp = true;
                    }
                }
            }
            return temp;
        }
    }
    return temp;
}
int main(){
    
    vector<int> trit;
    trit.push_back(0);
    trit.push_back(0);
    //cin >> trit;
    vector<int> succ = successor(trit);
    rep(i,succ.size()){
        cout << succ[i] << endl;
    }


}