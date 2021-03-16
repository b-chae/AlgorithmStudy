#include <iostream>

using namespace std;

int N;
bool board[1001][1001];
int ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void check(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx <= 1000 && ny <= 1000)
        {
            if (board[nx][ny])
            {
                int count = 0;
                for (int j = 0; j < 4; j++)
                {
                    int nnx = nx + dx[j];
                    int nny = ny + dy[j];
                    if (nnx >= 0 && nny >= 0 && nnx <= 1000 && nny <= 1000)
                    {
                        if (board[nnx][nny])
                            count++;
                    }
                }
                if (!board[x][y] && count == 3)
                    ans -= 1;
                else if (!board[x][y] && count == 2)
                    ans += 1;
            }
        }
    }

    board[x][y] = true;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        check(x, y);
        cout << ans << "\n";
    }

    return 0;
}
