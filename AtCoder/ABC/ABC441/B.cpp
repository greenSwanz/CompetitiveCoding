#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int N,M,Q;

    cin >> N >> M;

    string S, T;
     
    cin >> S;
    cin >> T;
    cin >> Q;

    rep(i,Q){
        string word;
        cin >> word;

        int inT = 0;
        int inS = 0;


        rep(i, size(word)){
            if(S.find(word[i]) != std::string::npos){
                inS += 1;
            }
            if(T.find(word[i]) != std::string::npos){
                inT += 1;
            }
        }

        int s = (size(word));
        if (inT == s && (inS != s)){
            cout << "Aoki" << endl;
        }
        else {if (inS == s && (inT != s)){
            cout << "Takahashi" << endl;
        }
        else{
            cout << "Unknown" << endl;
        }}
    }

    return 0;
    
}