#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string T_list[4] = {"eraser", "dreamer", "erase", "dream"};
    string joins[6] = {"erd", "ere", "amd", "ame", "see", "sed"};
    vector<int> threes;
    string S;
    cin >> S;
    
    if (S.length() < 4){
        cout << "NO" << endl;
        return 0; 
    }

    for (size_t i=0; i + 3 < (S.length()); i++){
        for (int j=0; j<6; j++){
            if (S.substr(i,3) == joins[j]){
                threes.push_back(i+1);
            }
        }
    }
    
    threes.push_back(S.length() -1);
    size_t i =0;
    int k =0;
    bool present = false;
    while (i +3<(S.length())){
        for (int j=0; j<4; j++){
            if (S.substr(i,(threes[k]-i)+1) == T_list[j]){
                present = true;
            }
            
        }
        if (present){
            if (k +1 <= threes.size()){
                if ((threes[k+1]- threes[k]) >2){
                i = threes[k] + 1;
            }
            k += 1;
            }
            else{
                cout <<"YES"<< endl;
                return 0; 
            }
            
        }
        else{
            cout << "NO" << endl;
            return 0;            
        }
        present = false;
        
    }
        
    cout << "YES" << endl;
    return 0;

}
