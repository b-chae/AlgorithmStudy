#include <iostream>

using namespace std;

int N;
int dp_table[1000001][4];

int dp(int n, int status)
{
    if (n == 0)
    {
        if (status == 1)
            return 1;
        else
            return 0;
    }
    else if (n == 1)
    {
        if (status == 1)
            return 2;
        else
            return 1;
    }

    int res = dp_table[n][status];
    if (res != 0)
        return res;

    switch (status)
    {
    case 1:
        res = ((long long)dp(n - 1, 1) * 2 + dp(n - 1, 2) + dp(n - 1, 3) + dp(n - 2, 1)) % 1000000007;
        break;
    case 2:
        res = ((long long)dp(n - 1, 1) + dp(n - 1, 3)) % 1000000007;
        break;
    case 3:
        res = ((long long)dp(n - 1, 1) + dp(n - 1, 2)) % 1000000007;
        break;
    }

    return dp_table[n][status] = res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    cout << dp(N, 1) << "\n";
    return 0;
}
