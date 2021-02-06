#include <iostream>

using namespace std;
int N;
string ans = "";

void solve(int n, string str)
{
    //cout << n << " " << str << "\n";

    if (n == N)
    {
        if (ans == "" || ans > str)
            ans = str;
        return;
    }

    if (ans.length() == N && ans < str)
        return;

    for (int i = 1; i <= 3; i++)
    {
        string now = str + char(i + '0');
        bool flag = true;
        for (int j = 1; j <= now.length() / 2; j++)
        {
            //cout << now.substr(now.length() - j, j) << "/" << now.substr(now.length() - 2 * j, j) << "\n";
            if (now.substr(now.length() - j, j) == now.substr(now.length() - 2 * j, j))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            solve(n + 1, now);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve(0, "");
    cout << ans << "\n";

    return 0;
}
