#include <iostream>

using namespace std;

string board[9];
bool isEnd = false;

bool check(int x, int y, int n)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == n + '0')
            return false;
        if (board[i][y] == n + '0')
            return false;
    }

    for (int i = x - x % 3; i < x - x % 3 + 3; i++)
    {
        for (int j = y - y % 3; j < y - y % 3 + 3; j++)
        {
            if (board[i][j] == n + '0')
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
            cout << board[i] << "\n";
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

    if (board[x][y] == '0')
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check(x, y, i))
            {
                board[x][y] = '0' + i;
                solve(nextx, nexty);
                board[x][y] = '0';
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
        cin >> board[i];
    }

    solve(0, 0);

    return 0;
}
