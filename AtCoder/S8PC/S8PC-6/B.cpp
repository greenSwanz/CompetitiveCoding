#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    int N;
    cin >> N;
    ll A[N];
    ll B[N];
    ll total = 0;

    ll start2 = 0, end2 = 0;
    //fills the lists with the start and end positions and initial sum
    rep(i,N){
        cin >> A[i] >> B[i];
        total += B[i] - A[i];
        start2+= A[i];
        end2 += B[i];
    }

    //sorts the lists in ascending order
    sort(A, A+N);
    sort(B, B+N);

    //start is the smallest and end is the largest stall visited
    ll start = A[0];
    ll end = B[N-1];

    //difference between the furthest and closest stall from entrance and exit
    ll A_diff = A[N-1] - A[0];
    ll B_diff = B[N-1] - B[0];


    ll min_diff =0 , max_diff =0;
    //initial distances from initial start and end
    rep(j,N){
            min_diff += abs(A[j] - start);
            max_diff += abs(B[j] - end);
    }

    ll min_diff_next = 0;
    rep(i,start2*N){
        min_diff_next = 0;
        rep(j,N){
           min_diff_next += abs(A[j] - start);
        }
        if(min_diff_next>min_diff){
            start -= 1;
            break;
        }
        else{
            min_diff = min_diff_next;
        }
        start +=1;
    }
     
    ll max_diff_next = 0;
    rep(i,B_diff){
        max_diff_next = 0;
        rep(j,N){
           max_diff_next += abs(end - B[j]);
        }
        if(max_diff_next>max_diff){
            end += 1;
            break;
        }
        else{
            max_diff = max_diff_next;
        }
        end -= 1;
    }

    cout << (total + min_diff + max_diff) << endl;
}