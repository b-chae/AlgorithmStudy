#include <iostream>
#include <cmath>

using namespace std;
int N, M;
int board[50][50];
int room[50][50];
int c[2500];
bool visited[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int w[4] = {4, 1, 8, 2};
int ans2 = 0;

int dfs(int i, int j, int n)
{
    visited[i][j] = true;
    room[i][j] = n;

    int res = 1;

    for (int x = 0; x < 4; x++)
    {
        int ni = i + dx[x];
        int nj = j + dy[x];
        if ((board[i][j] & w[x]) == 0)
        {
            if (ni >= 0 && nj >= 0 && ni < N && nj < M && !visited[ni][nj])
            {
                res += dfs(ni, nj, n);
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans1 = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (!visited[i][j])
            {
                c[ans1] = dfs(i, j, ans1);
                ans2 = max(c[ans1], ans2);
                ans1++;
            }
        }
    }

    int ans3 = c[0];

    for (int dir = 0; dir < 4; dir++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M && (board[i][j] & w[dir]) == w[dir] && room[i][j] != room[nx][ny])
                {
                    ans3 = max(ans3, c[room[i][j]] + c[room[nx][ny]]);
                }
            }
        }
    }

    cout << ans1 << "\n"
         << ans2 << "\n"
         << ans3 << "\n";

    return 0;
}
