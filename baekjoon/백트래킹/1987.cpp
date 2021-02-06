#include <iostream>

using namespace std;

int R, C;
string board[20];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool include[26];
int ans = 0;

void dfs(int i, int j, int dist)
{
    ans = max(ans, dist);
    for (int x = 0; x < 4; x++)
    {
        int nx = i + dx[x];
        int ny = j + dy[x];
        if (nx >= 0 && ny >= 0 && nx < R && ny < C && !include[board[nx][ny] - 'A'])
        {
            include[board[nx][ny] - 'A'] = true;
            dfs(nx, ny, dist + 1);
            include[board[nx][ny] - 'A'] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    int i, j;
    for (i = 0; i < R; i++)
    {
        cin >> board[i];
    }

    include[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans << "\n";

    return 0;
}
