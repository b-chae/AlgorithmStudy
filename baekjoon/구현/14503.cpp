#include <iostream>

using namespace std;

int N, M;
int R, C, dir;
bool visited[50][50];
bool wall[50][50];

// 0  1  2 3
// 위 왼 아 오
// 위 동 아 왼
int dx[8] = {0, 1, 0, -1, 0, 1, 0, -1};
int dy[8] = {-1, 0, 1, 0, -1, 0, 1, 0};
int bx[4] = {1, 0, -1, 0};
int by[4] = {0, 1, 0, -1};

int dfs(int x, int y, int d)
{
    int res = 0;

    if (!visited[x][y])
    {
        res += 1;
        visited[x][y] = true;
    }

    //cout << x << " " << y << " " << d << "\n";

    bool flag = false;

    for (int i = d; i < d + 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M)
        {
            if (!visited[nx][ny] && !wall[nx][ny])
            {
                res += dfs(nx, ny, (i + 1) % 4);
                flag = true;
                break;
            }
        }
    }

    if (!flag)
    {
        int nx = x + bx[d];
        int ny = y + by[d];
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
            cin >> wall[i][j];
        }
    }

    if (dir == 1)
    {
        dir = 3;
    }
    else if (dir == 3)
    {
        dir = 1;
    }

    cout << dfs(R, C, dir) << "\n";

    return 0;
}
