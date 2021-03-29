#include <iostream>

using namespace std;

int Acount = 0, Bcount = 0, Ccount = 0;
char ans[51];
bool DP[51][51][51][3][3];

bool solve(int a, int b, int c, int pre, int pre2)
{
    if (a == Acount && b == Bcount && c == Ccount)
        return true;

    if (DP[a][b][c][pre][pre2])
        return false;
    DP[a][b][c][pre][pre2] = true;

    if (a < Acount)
    {
        ans[a + b + c] = 'A';
        if (solve(a + 1, b, c, 0, pre))
            return true;
    }
    if (b < Bcount && pre != 1)
    {
        ans[a + b + c] = 'B';
        if (solve(a, b + 1, c, 1, pre))
            return true;
    }
    if (c < Ccount && pre != 2 && pre2 != 2)
    {
        ans[a + b + c] = 'C';
        if (solve(a, b, c + 1, 2, pre))
            return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
            Acount++;
        else if (s[i] == 'B')
            Bcount++;
        else
            Ccount++;
    }

    if (solve(0, 0, 0, -1, -1))
    {
        for (int i = 0; i < s.length(); i++)
        {
            cout << ans[i];
        }
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}
