#include <iostream>
#include <queue>

using namespace std;

struct Move
{
    int x, y, turn;
    unsigned int key;
};

bool visited[50][50][128];
string board[50];
int N, M;
queue<Move> bfsQueue;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int i, j;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
        for (j = 0; j < M; j++)
        {
            if (board[i][j] == '0')
            {
                bfsQueue.push({i, j, 0, 0});
                visited[i][j][0] = true;
            }
        }
    }

    while (!bfsQueue.empty())
    {
        int x = bfsQueue.front().x;
        int y = bfsQueue.front().y;
        int turn = bfsQueue.front().turn;
        unsigned int key = bfsQueue.front().key;
        bfsQueue.pop();

        if (board[x][y] == '1')
        {
            cout << turn << "\n";
            return 0;
        }

        if (board[x][y] >= 'a' && board[x][y] <= 'f')
        {
            unsigned int k = 1 << (board[x][y] - 'a');
            key = (key | k);
        }
        else if (board[x][y] >= 'A' && board[x][y] <= 'F')
        {
            unsigned int k = 1 << (board[x][y] - 'A');
            if ((key & k) != k)
                continue;
        }

        for (i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny][key] && board[nx][ny] != '#')
            {
                bfsQueue.push({nx, ny, turn + 1, key});
                visited[nx][ny][key] = true;
            }
        }
    }

    cout << "-1\n";
    return 0;
}
