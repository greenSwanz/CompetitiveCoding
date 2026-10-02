#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H, W;
    cin >> H >> W;

    char A[(H * W)];
    rep(i,(H*W)){
        cin >> A[i];
    }

    queue<int> q;
    q.push(0);

    int counter = 0;
    int moves[4];

    int temp;
    bool visited[(H*W)] = {};
    
    visited[0] = true;

    int layers[H*W];
    layers[0] = 1;

    while (!q.empty()){
        temp = q.front();      
        moves[0] = temp - 1; //left
        moves[1] = temp + 1; //right
        moves[2] = temp - W; //up 
        moves[3] = temp + W; //down
        rep(i,4){
            if(moves[i] == ((H*W)-1)){
                int newcounter = 0;
                rep(j,(H*W)){
                    if((A[j] == '.')){
                        newcounter += 1;
                    }                     
                }
                cout << (newcounter - layers[temp] - 1) << endl;
                return 0;
            }
        }
        int t = 0;
        rep(i,2){ 
            if((A[moves[i]] == '.') && (!visited[moves[i]]) && (moves[i] >= ((temp/W)* W)) && (moves[i] <= ((temp/W + 1)*W - 1))){
                visited[moves[i]] = true;
                q.push(moves[i]);                
                layers[moves[i]] = layers[temp] + 1;
            }
                
        }
        repp(i,2,4){ 
            if((A[moves[i]] == '.') && (!visited[moves[i]]) && (moves[i] >= 0) && (moves[i] < (H*W))){
                visited[moves[i]] = true;
                q.push(moves[i]);                
                layers[moves[i]] = layers[temp] + 1;
            }
                
        }
        q.pop();
    }

    cout << -1 << endl;
    return 0;

}