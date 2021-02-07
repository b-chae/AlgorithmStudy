#include <iostream>

using namespace std;

int board[9][9];
bool isEnd = false;

bool check(int x, int y, int n)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == n)
            return false;
        if (board[i][y] == n)
            return false;
    }

    for (int i = x - x % 3; i < x - x % 3 + 3; i++)
    {
        for (int j = y - y % 3; j < y - y % 3 + 3; j++)
        {
            if (board[i][j] == n)
                return false;
        }
    }

    return true;
}

void solve(int x, int y)
{
    if (x == 9 && y == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        isEnd = true;
        return;
    }

    if (isEnd)
        return;

    int nextx = x;
    int nexty = y + 1;
    if (nexty == 9)
    {
        nextx++;
        nexty = 0;
    }

    if (board[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check(x, y, i))
            {
                board[x][y] = i;
                solve(nextx, nexty);
                board[x][y] = 0;
            }
        }

        return;
    }

    solve(nextx, nexty);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j;

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(0, 0);

    return 0;
}
