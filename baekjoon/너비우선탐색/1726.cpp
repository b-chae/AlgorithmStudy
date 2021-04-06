#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int x, y, dir, d;
};

int N, M;
bool wall[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<node> bfsQueue;
int sx, sy, sdir, ex, ey, edir;
bool visited[100][100][4];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> wall[i][j];
        }
    }
    cin >> sx >> sy >> sdir >> ex >> ey >> edir;

    ex--;
    ey--;
    edir--;
    bfsQueue.push({sx - 1, sy - 1, sdir - 1, 0});
    visited[sx][sy][sdir] = true;

    while (!bfsQueue.empty())
    {
        int x = bfsQueue.front().x;
        int y = bfsQueue.front().y;
        int dir = bfsQueue.front().dir;
        int d = bfsQueue.front().d;
        bfsQueue.pop();

        if (x == ex && y == ey && dir == edir)
        {
            cout << d << "\n";
            break;
        }

        for (int i = 1; i <= 3; i++)
        {
            int nx = x + dx[dir] * i;
            int ny = y + dy[dir] * i;
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (wall[nx][ny])
                    break;

                if (!visited[nx][ny][dir])
                {
                    bfsQueue.push({nx, ny, dir, d + 1});
                    visited[nx][ny][dir] = true;
                }
            }
        }

        if (!visited[x][y][(dir + 2) % 4])
        {
            bfsQueue.push({x, y, (dir + 2) % 4, d + 1});
            visited[x][y][(dir + 2) % 4] = true;
        }
        if (!visited[x][y][(dir + 3 - dir % 2 * 2) % 4])
        {
            bfsQueue.push({x, y, (dir + 3 - dir % 2 * 2) % 4, d + 1});
            visited[x][y][(dir + 3 - dir % 2 * 2) % 4] = true;
        }
    }
    return 0;
}
