#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;

    int len = S.length();
    vector<int> indices;
    indices.push_back(-1);
    for (int i =0; i<len; i++){
        char t = S[i];
        if ((t != 'A') && (t != 'C') && (t !='G')&& (t != 'T')){
            indices.push_back(i);
        }
    }
    indices.push_back(len);

    int temp = indices[0];
    for (int j=0; j + 1< indices.size(); j++){
        if ((indices[j+1]- indices[j])> temp){
            temp = (indices[j+1] - indices[j]) -1;
        }
    }
    cout << temp << endl;
    return 0;
    
}