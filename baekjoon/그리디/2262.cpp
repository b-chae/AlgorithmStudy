#include <iostream>

using namespace std;

int N;
int A[256];
int winner[256][256];
int DP[256][256];

int solve(int start, int end){

    if(start == end) {
        return 0;
    }
    if(start == end-1){
        return DP[start][end] = abs(A[start]-A[end]);
    }
    if(DP[start][end]!=0) return DP[start][end];

    int result = 999999999;
    for(int i=start; i<end; i++){
        result = min(result, solve(start, i) + solve(i+1, end) + abs(winner[start][i]-winner[i+1][end]));
    }
    return DP[start][end] = result;
}

int main(){

    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];

    for(int i=0; i<N; i++){
        winner[i][i] = A[i];
        for(int j=i+1; j<N; j++){
            winner[i][j] = min(winner[i][j-1], A[j]);
        }
    }

    cout << solve(0, N-1) << "\n";

    return 0;
}