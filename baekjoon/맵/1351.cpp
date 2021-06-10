#include <iostream>
#include <map>

using namespace std;

long long N, P, Q;
map<long long, long long> d;

long long dp(long long n){
    if(d.find(n) == d.end()){
        return d[n] = dp(n/P) + dp(n/Q);
    }
    return d[n];
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;

    d[0] = 1;

    cout << dp(N) << "\n";

    return 0;
}