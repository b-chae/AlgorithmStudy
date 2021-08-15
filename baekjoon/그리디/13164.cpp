#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int A[300000];
int diff[300000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    for(int i=0; i<N-1; i++){
        diff[i] = A[i+1]-A[i];
    }

    sort(diff, diff+N-1);
    long long ans = 0;

    for(int i=0; i<N-K; i++){
        ans += diff[i];
    }
    cout << ans << "\n";

    return 0;
}
