#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
string tmp[1000];
string board[1000];
bool DP[1000][1000];


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> tmp[i];
    }

    for(int i=0; i<M; i++){
        board[i] = "";
        for(int j=N-1; j>=0; j--){
            board[i] += tmp[j][i];
        }
    }

    sort(board, board+M);

    int ans = 0;
    bool flag = true;

    for(int i=1; i<M; i++){
        if(board[i][0] == board[i-1][0]){
            DP[i][0] = true;
            flag = false;
        }
    }

    if(flag) ans++;
    
    for(int j=1; j<N-1; j++){
        flag=true;
        for(int i=1; i<M-1; i++){
            if(DP[i][j-1] && board[i-1][j]==board[i][j]){
                DP[i][j] = true;
                flag=false;
            }
        }
        if(flag)ans++;
    }
    
    cout << ans << "\n";

    return 0;
}
