#include <iostream>

using namespace std;

int N, M;
string board[10000];
bool visited[10000][500];
int dir[3][2] = {{-1, 1}, {0, 1}, {1, 1}};

bool dfs(int i, int j)
{
    visited[i][j] = true;
    if (j == M - 1)
        return true;

    for (int d = 0; d < 3; d++)
    {
        int nx = i + dir[d][0];
        int ny = j + dir[d][1];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M && board[nx][ny] == '.' && !visited[nx][ny])
        {
            if (dfs(nx, ny))
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int i, j;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    int ans = 0;
    for (i = 0; i < N; i++)
    {
        if (board[i][0] == '.' && !visited[i][0])
        {
            if (dfs(i, 0))
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
