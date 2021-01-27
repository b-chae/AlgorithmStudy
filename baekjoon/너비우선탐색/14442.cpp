#include <iostream>
#include <queue>

using namespace std;

struct Move
{
    int x, y, k, turn;
};

string board[1000];
bool visited[1000][1000][10];
int N, M, K;
queue<Move> bfsQueue;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    int i, j;
    for (i = 0; i < N; i++)
        cin >> board[i];

    if (board[0][0] == '0')
    {
        bfsQueue.push({0, 0, 0, 1});
        visited[0][0][0] = true;
    }
    else if (K > 0)
    {
        bfsQueue.push({0, 0, 1, 1});
        visited[0][0][1] = true;
    }

    while (!bfsQueue.empty())
    {
        int x = bfsQueue.front().x;
        int y = bfsQueue.front().y;
        int k = bfsQueue.front().k;
        int turn = bfsQueue.front().turn;
        bfsQueue.pop();

        if (x == N - 1 && y == M - 1)
        {
            cout << turn << "\n";
            return 0;
        }

        for (i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (board[nx][ny] == '0' && !visited[nx][ny][k])
                {
                    bfsQueue.push({nx, ny, k, turn + 1});
                    visited[nx][ny][k] = true;
                }
                else if (board[nx][ny] == '1' && k < K && !visited[nx][ny][k + 1])
                {
                    bfsQueue.push({nx, ny, k + 1, turn + 1});
                    visited[nx][ny][k + 1] = true;
                }
            }
        }
    }

    cout << "-1\n";
    return 0;
}
