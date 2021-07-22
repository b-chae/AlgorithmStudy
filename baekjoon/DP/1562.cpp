#include <iostream>

using namespace std;

int N;
int DP[101][10][1024];

int main(){

    cin >> N;
    for(int i=1; i<10; i++){
        DP[1][i][1<<i] = 1;
    }
    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<1024; k++){
                int nk = k | (1<<j);
                if(j>0)
                DP[i][j][nk] += DP[i-1][j-1][k];
                DP[i][j][nk] %= 1000000000;
                if(j<9)
                DP[i][j][nk] += DP[i-1][j+1][k];
                DP[i][j][nk] %= 1000000000;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<10; i++){
        ans += DP[N][i][1023];
        ans %= 1000000000;
    }
    cout << ans << "\n";
    return 0;
}