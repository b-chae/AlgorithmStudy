#include <iostream>
#include <queue>

using namespace std;

int dist[100][100];
int board[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N;

struct bfs
{
    int x, y, c, turn;

    bool operator<(const bfs &a) const
    {
        return turn > a.turn;
    }
};

priority_queue<bfs> bfsQueue;

void dfs(int i, int j, int n)
{
    visited[i][j] = true;
    board[i][j] = n;
    bfsQueue.push({i, j, n, 0});

    for (int x = 0; x < 4; x++)
    {
        int nx = i + dx[x];
        int ny = j + dy[x];

        if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && board[nx][ny] != 0)
        {
            dfs(nx, ny, n);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int n = 1, i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (!visited[i][j] && board[i][j] != 0)
            {
                dfs(i, j, n);
                n++;
            }
        }
    }

    while (!bfsQueue.empty())
    {
        int x = bfsQueue.top().x;
        int y = bfsQueue.top().y;
        int turn = bfsQueue.top().turn;
        int c = bfsQueue.top().c;
        bfsQueue.pop();

        if (c == -1)
        {
            cout << turn << "\n";
            return 0;
        }

        for (i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (board[nx][ny] == 0 && !visited[nx][ny])
                {
                    board[nx][ny] = c;
                    dist[nx][ny] = turn + 1;
                    bfsQueue.push({nx, ny, c, turn + 1});
                    visited[nx][ny] = true;
                }
                else if (board[nx][ny] != 0 && board[nx][ny] != c)
                {
                    bfsQueue.push({nx, ny, -1, turn + dist[nx][ny]});
                }
            }
        }
    }

    return 0;
}
