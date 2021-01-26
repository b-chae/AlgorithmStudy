#include <iostream>

using namespace std;
int N, M;
int board[500][500];
bool visited[500][500];
int dp[500][500];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dfs(int i, int j)
{
    int res = dp[i][j];
    visited[i][j] = true;

    for (int x = 0; x < 4; x++)
    {
        int tx = i + dx[x];
        int ty = j + dy[x];
        if (tx >= 0 && ty >= 0 && tx < N && ty < M && board[tx][ty] < board[i][j])
        {
            if (!visited[tx][ty])
                res += dfs(tx, ty);
            else
                res += dp[tx][ty];
        }
    }

    dp[i][j] = res;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    dp[N - 1][M - 1] = 1;
    cout << dfs(0, 0) << "\n";

    return 0;
}
