#include <iostream>
#include <queue>

using namespace std;

int N, M;

struct node
{
    int x, y, through, by;

    bool operator<(const node &a) const
    {
        if (through == a.through)
            return by > a.by;
        return through > a.through;
    }
};

priority_queue<node> pq;
string board[50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[50][50];

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
            if (board[i][j] == 'S')
            {
                pq.push({i, j, 0, 0});
            }
        }
    }

    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int through = pq.top().through;
        int by = pq.top().by;
        pq.pop();

        if (board[x][y] == 'F')
        {
            cout << through << " " << by << "\n";
            break;
        }

        for (i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny])
            {
                if (board[nx][ny] == 'g')
                {
                    pq.push({nx, ny, through + 1, by});
                    visited[nx][ny] = true;
                }
                else if (board[nx][ny] == '.')
                {
                    bool trash = false;
                    for (j = 0; j < 4; j++)
                    {
                        int cx = nx + dx[j];
                        int cy = ny + dy[j];
                        if (cx >= 0 && cy >= 0 && cx < N && cy < M && board[cx][cy] == 'g')
                        {
                            trash = true;
                            break;
                        }
                    }
                    if (trash)
                    {
                        pq.push({nx, ny, through, by + 1});
                    }
                    else
                    {
                        pq.push({nx, ny, through, by});
                    }
                    visited[nx][ny] = true;
                }
                else
                {
                    pq.push({nx, ny, through, by});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    return 0;
}
