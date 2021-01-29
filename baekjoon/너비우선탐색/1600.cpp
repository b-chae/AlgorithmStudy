#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int x, y, k, turn;
};

int K, W, H;
int board[200][200];
bool visited[200][200][31];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int mx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int my[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

queue<Node> bfsQueue;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> H >> W;
    int i, j;
    for (i = 0; i < W; i++)
    {
        for (j = 0; j < H; j++)
        {
            cin >> board[i][j];
        }
    }

    bfsQueue.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!bfsQueue.empty())
    {
        int x = bfsQueue.front().x;
        int y = bfsQueue.front().y;
        int k = bfsQueue.front().k;
        int turn = bfsQueue.front().turn;
        bfsQueue.pop();

        if (x == W - 1 && y == H - 1)
        {
            cout << turn << "\n";
            return 0;
        }

        for (i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < W && ny < H && board[nx][ny] == 0 && !visited[nx][ny][k])
            {
                bfsQueue.push({nx, ny, k, turn + 1});
                visited[nx][ny][k] = true;
            }
        }
        if (k < K)
        {
            for (i = 0; i < 8; i++)
            {
                int nx = x + mx[i];
                int ny = y + my[i];
                if (nx >= 0 && ny >= 0 && nx < W && ny < H && board[nx][ny] == 0 && !visited[nx][ny][k + 1])
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
