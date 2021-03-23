#include <iostream>
#include <queue>

using namespace std;

#define RED 0
#define BLUE 1

struct node
{
    int x, y, move;
};

int N, M;
string board[10];
queue<node> bfs[2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'R')
            {
                bfs[RED].push({i, j, 0});
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B')
            {
                bfs[BLUE].push({i, j, 0});
                board[i][j] = '.';
            }
        }
    }

    while (!bfs[RED].empty())
    {
        int rx = bfs[RED].front().x;
        int ry = bfs[RED].front().y;
        int bx = bfs[BLUE].front().x;
        int by = bfs[BLUE].front().y;
        int move = bfs[RED].front().move;

        if (bx == -1)
        {
            bfs[RED].pop();
            bfs[BLUE].pop();
            continue;
        }

        if (board[rx][ry] == 'O')
        {
            cout << "1\n";
            return 0;
        }

        if (move >= 10)
        {
            bfs[RED].pop();
            bfs[BLUE].pop();
            continue;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int idx = 0;
            if (dir == 0)
            {
                if (ry > by)
                    idx = 1;
            }
            else if (dir == 1)
            {
                if (by > ry)
                    idx = 1;
            }
            else if (dir == 2)
            {
                if (bx > rx)
                    idx = 1;
            }
            else
            {
                if (bx < rx)
                {
                    idx = 1;
                }
            }

            for (int t = 0; t < 2; t++)
            {
                int x = bfs[idx].front().x;
                int y = bfs[idx].front().y;

                while (true)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < N && ny < M)
                    {
                        if (board[nx][ny] == 'O')
                        {
                            if (idx == RED)
                            {
                                x = nx;
                                y = ny;
                                break;
                            }
                            else
                            {
                                x = -1;
                                y = -1;
                                break;
                            }
                        }
                        else if (board[nx][ny] == '#')
                            break;
                        else
                        {
                            if (t == 1 && bfs[1 - idx].back().x == nx && bfs[1 - idx].back().y == ny)
                            {
                                break;
                            }
                            else
                            {
                                x = nx;
                                y = ny;
                            }
                        }
                    }
                }

                bfs[idx].push({x, y, move + 1});
                idx = 1 - idx;
            }
        }

        bfs[RED].pop();
        bfs[BLUE].pop();
    }

    cout << "0\n";

    return 0;
}
