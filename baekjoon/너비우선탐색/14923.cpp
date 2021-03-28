#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int x, y, z;
    bool broken;
};

int N, M, sx, sy, ex, ey;
bool wall[1000][1000];
bool visited[1000][1000][2];
queue<node> bfsQueue;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> sx >> sy >> ex >> ey;
    sx--;
    sy--;
    ex--;
    ey--;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> wall[i][j];
        }
    }

    bfsQueue.push({sx, sy, 0, false});
    visited[sx][sy][0] = true;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!bfsQueue.empty())
    {
        int x = bfsQueue.front().x;
        int y = bfsQueue.front().y;
        int z = bfsQueue.front().z;
        bool broken = bfsQueue.front().broken;
        bfsQueue.pop();

        if (ex == x && ey == y)
        {
            cout << z << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (!wall[nx][ny] && !visited[nx][ny][broken])
                {
                    bfsQueue.push({nx, ny, z + 1, broken});
                    visited[nx][ny][broken] = true;
                }
                else if (wall[nx][ny] && !visited[nx][ny][true] && !broken)
                {
                    bfsQueue.push({nx, ny, z + 1, true});
                    visited[nx][ny][true] = true;
                }
            }
        }
    }

    cout << "-1\n";

    return 0;
}
