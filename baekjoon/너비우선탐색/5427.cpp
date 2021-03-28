#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int type, x, y, d;
};

int T, N, M;
string board[1000];
bool visited[1000][1000][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        queue<node> bfsQueue;
        cin >> M >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> board[i];
            for (int j = 0; j < M; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    visited[i][j][k] = false;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == '*')
                {
                    bfsQueue.push({1, i, j, 0});
                    visited[i][j][1] = true;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == '@')
                {
                    bfsQueue.push({0, i, j, 0});
                    visited[i][j][0] = true;
                }
            }
        }

        bool flag = false;

        while (!bfsQueue.empty())
        {
            int type = bfsQueue.front().type;
            int x = bfsQueue.front().x;
            int y = bfsQueue.front().y;
            int d = bfsQueue.front().d;
            bfsQueue.pop();

            if (type == 0 && (x <= 0 || y <= 0 || x >= N - 1 || y >= M - 1))
            {
                cout << d + 1 << "\n";
                flag = true;
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (type == 1 && nx >= 0 && ny >= 0 && nx < N && ny < M)
                {
                    if (!visited[nx][ny][1] && board[nx][ny] != '#')
                    {
                        bfsQueue.push({1, nx, ny, d + 1});
                        visited[nx][ny][1] = true;
                        board[nx][ny] = '*';
                    }
                }
                else if (type == 0 && nx >= 0 && ny >= 0 && nx < N && ny < M)
                {
                    if (!visited[nx][ny][0] && board[nx][ny] == '.')
                    {
                        bfsQueue.push({0, nx, ny, d + 1});
                        visited[nx][ny][0] = true;
                    }
                }
            }
        }

        if (!flag)
        {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
