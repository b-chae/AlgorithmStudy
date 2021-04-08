#include <iostream>

using namespace std;

string board[12];
bool visited[12][6];
int check[12][6];

void initvisit()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            visited[i][j] = false;
            check[i][j] = 0;
        }
    }
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int i, int j, int n)
{
    visited[i][j] = true;
    check[i][j] = n;

    int res = 1;

    for (int d = 0; d < 4; d++)
    {
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx >= 0 && ny >= 0 && nx < 12 && ny < 6 && !visited[nx][ny] && board[i][j] == board[nx][ny])
        {
            res += dfs(nx, ny, n);
        }
    }

    return res;
}

void gravity()
{
    for (int i = 11; i >= 0; i--)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == '.')
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (board[k][j] != '.')
                    {
                        board[i][j] = board[k][j];
                        board[k][j] = '.';
                        break;
                    }
                }
            }
        }
    }
}

int ans = 0;

void boom(int n)
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (check[i][j] == n)
            {
                board[i][j] = '.';
                visited[i][j] = false;
                check[i][j] = 0;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 12; i++)
    {
        cin >> board[i];
    }

    int n;
    bool flag;

    do
    {
        flag = false;
        n = 1;
        initvisit();
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (board[i][j] != '.' && !visited[i][j])
                {
                    int a = dfs(i, j, n);
                    if (a > 3)
                    {
                        boom(n);
                        flag = true;
                    }
                    n++;
                }
            }
        }
        if (flag)
            ans++;
        gravity();
    } while (flag == true);

    cout << ans << "\n";

    return 0;
}
