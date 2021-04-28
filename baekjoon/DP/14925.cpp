#include <iostream>

using namespace std;

int N, M;
int board[1000][1000];
int D[1000][1000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j]==0) D[i][j] = 1;
        }
    }

    for(int i=1; i<N; i++){
        for(int j=1; j<M; j++){
            if(board[i][j] != 0) continue;
            int k = min(D[i-1][j], D[i][j-1]);
            k = min(k, D[i-1][j-1]);
            D[i][j] = k+1;
        }
    }

    int ans = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            ans = max(ans, D[i][j]);
        }
    }

    cout << ans << "\n";

    return 0;
}
