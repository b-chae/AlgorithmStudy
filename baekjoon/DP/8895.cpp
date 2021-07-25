#include <iostream>

using namespace std;

long long DP[21][21][21];
int T, N, L, R;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    DP[1][1][1] = 1;
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N >> L >> R;
        for(int i=2; i<=N; i++){
            for(int j=1; j<=L; j++){
                for(int k=1; k<=R; k++){
                    DP[i][j][k] = DP[i-1][j-1][k] + DP[i-1][j][k-1] + (i-2)*DP[i-1][j][k];
                }
            }
        }
        cout << DP[N][L][R] << "\n";
    }

    return 0;
}