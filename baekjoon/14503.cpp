#include <iostream>

using namespace std;

int N, M;
int R, C, dir;
bool visited[50][50];
bool wall[50][50];

int dx[8] = {0, 1, 0, -1, 0, 1, 0, -1};
int dy[8] = {-1, 0, 1, 0, -1, 0, 1, 0};
int bx[4] = {1, 0, -1, 0};
int by[4] = {0, 1, 0, -1};

int dfs(int x, int y, int d)
{
    int res = 0;

    if (!visited[x][y])
        res += 1;

    visited[x][y] = true;

    cout << x << " " << y << " " << d << "\n";

    for (int i = d; i < d + 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M)
        {
            if (!visited[nx][ny] && !wall[nx][ny])
            {
                res += dfs(nx, ny, (i + 1) % 4);
                break;
            }
        }
    }

    if (res == 1)
    {
        int nx = x + bx[d];
        int ny = y + by[d];
        cout << x << "/" << y << "/" << nx << "/" << ny << "\n";
        if (nx >= 0 && ny >= 0 && nx < N && ny < M && !wall[nx][ny])
        {
            res += dfs(nx, ny, d);
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> R >> C >> dir;

    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            int t;
            cin >> t;
            if (t == 1)
                wall[i][j] = true;
        }
    }

    cout << dfs(R, C, dir) << "\n";

    return 0;
}
