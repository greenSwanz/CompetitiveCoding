#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
ll fact(ll n){
    if(n ==1){
        return n;
    }
    return (n * fact(n-1));
}

int main(){
    int N;
    cin >> N;
    ll N_fact = fact(N-1);
    ll XCoords[N];
    ll YCoords[N];
    P coords[N];
    rep(i,N){
        cin >> coords[i].first >> coords[i].second;
    }

    long double sum = 0;
    double distances[N][N];

    rep(i,N){
        rep(j,N){
            distances[i][j] = sqrt(
                (coords[j].first - coords[i].first) * (coords[j].first - coords[i].first) + 
                (coords[j].second - coords[i].second) * (coords[j].second - coords[i].second)
            );
            sum += distances[i][j] * N_fact;

        }
    }

    cout << std::setprecision(11) << sum/(fact(N)) << endl;
    
}