#include <iostream>
#include <queue>

using namespace std;

int N, M;
string board[50];

struct node{
    int x, y, n, k;
};

queue<node> q;
bool visited[50][50];
int DP[50][50];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(int x, int y){
    if(DP[x][y]!=0) return DP[x][y];
    int res = 0;
    int k = board[x][y] - '0';
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x+dx[i]*k;
        int ny = y+dy[i]*k;
        if(nx<0||ny<0||nx>=N||ny>=M||board[nx][ny]=='H') continue;
        if(visited[nx][ny]) return DP[x][y] = 1000000;
        res = max(res, dfs(nx, ny));
    }
    visited[x][y] = false;
    return DP[x][y] = res + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> board[i];
    }

    dfs(0,0);
    if(DP[0][0] >= 1000000) cout << "-1\n";
    else cout << DP[0][0] << "\n";

    return 0;
}