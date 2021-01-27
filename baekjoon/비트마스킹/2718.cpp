#include <iostream>

using namespace std;
int T, N;
int dp_table[30][6];

int dp(int n, int status)
{
    int res;
    if (dp_table[n][status] != 0)
        return dp_table[n][status];

    if (n == 0 && status == 1)
        return 1;
    else if (n == 0)
        return 0;
    if (n == 1)
    {
        if (status == 4)
            return 0;
        return 1;
    }

    switch (status)
    {
    case 1:
        res = dp(n - 1, 1) + dp(n - 1, 2) + dp(n - 1, 3) + dp(n - 1, 5) + dp(n - 2, 1);
        break;
    case 2:
        res = dp(n - 1, 1) + dp(n - 1, 3);
        break;
    case 3:
        res = dp(n - 1, 1) + dp(n - 1, 2);
        break;
    case 4:
        res = dp(n - 1, 5);
        break;
    case 5:
        res = dp(n - 1, 1) + dp(n - 1, 4);
        break;
    }
    return dp_table[n][status] = res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int i;
    for (i = 0; i < T; i++)
    {
        cin >> N;
        cout << dp(N, 1) << "\n";
    }
    return 0;
}
