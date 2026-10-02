#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    vector<int> p = {2,3,5,7,11,13,17,19,23,29,31,37,41,47,53,59,67,71,83,89,101,107,109,113,127,131,137,139,149,157,167,179,181,191,197,199,211,227,233,239,251,257,263,269,281,293,307,311,317,337,347,353,359,379,389,401,409,419,431,443,449,461,467,479,487,491,499,503,509,521,541,557,563,569,571};
    int total = 0;
    repp(i,2,200){
        if(i in p){
            total += 200/i;
        }
    }
    cout << total << endl;
}