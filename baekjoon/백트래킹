#include <iostream>
#include <cmath>

using namespace std;
char board[10][10];
int ans = 100;

bool check(int i, int j, int size)
{
    if (i + size - 1 >= 10 || j + size - 1 >= 10)
        return false;

    bool flag = true;
    for (int x = i; x <= i + size - 1; x++)
    {
        for (int y = j; y <= j + size - 1 && flag; y++)
        {
            if (board[x][y] == '0')
                flag = false;
        }
    }
    return flag;
}

void cover(int i, int j, int size)
{
    for (int x = i; x <= i + size - 1; x++)
    {
        for (int y = j; y <= j + size - 1; y++)
        {
            board[x][y] = '0';
        }
    }
}

void uncover(int i, int j, int size)
{
    for (int x = i; x <= i + size - 1; x++)
    {
        for (int y = j; y <= j + size - 1; y++)
        {
            board[x][y] = '1';
        }
    }
}

void dfs(int i, int j, int count, int paper, int arg[])
{
    int size_paper[5] = {arg[0], arg[1], arg[2], arg[3], arg[4]};

    if (count == 0)
    {
        ans = min(ans, paper);
        return;
    }

    if (i == 10)
    {
        return;
    }

    if (ans <= paper)
        return;

    int nexti = i;
    int nextj = j + 1;
    if (nextj == 10)
    {
        nexti++;
        nextj = 0;
    }

    if (board[i][j] == '1')
    {
        for (int size = 5; size >= 1; size--)
        {
            if (check(i, j, size) && size_paper[size - 1] < 5)
            {
                //cout << i << " " << j << " " << size << "\n";
                cover(i, j, size);
                int arr[5] = {size_paper[0], size_paper[1], size_paper[2], size_paper[3], size_paper[4]};
                arr[size - 1]++;
                //cout << i << " " << j << " " << count - size * size << " " << paper + 1 << " " << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << "\n";
                dfs(nexti, nextj, count - size * size, paper + 1, arr);
                uncover(i, j, size);
            }
        }
    }
    else
    {
        dfs(nexti, nextj, count, paper, size_paper);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j;
    int count = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '1')
                count++;
        }
    }

    int arr[5] = {0, 0, 0, 0, 0};
    dfs(0, 0, count, 0, arr);

    if (ans == 100)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }
    return 0;
}
