#include <iostream>

using namespace std;

int N, M;

int DP[101][51];
int A[101];

int solve(int n, int M){

    if(M==0) return 0;
    if(n<=0) return -3276800;
    if(DP[n][M] != 0) return DP[n][M];

    DP[n][M] = solve(n-1, M);
    int sum = 0;
    for(int i=n; i>0; i--){
        sum += A[i];
        DP[n][M] = max(DP[n][M], solve(i-2, M-1) + sum);
    }
    return DP[n][M];
}

int main(){

    cin >> N >> M;

    for(int i=1; i<=N; i++){
        cin >> A[i];
    }

    cout << solve(N, M);
    
    return 0;
}