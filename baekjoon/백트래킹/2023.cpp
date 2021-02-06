#include <iostream>

using namespace std;
int N;

bool check(string str)
{
    int n = 0;

    for (int i = 0; i < str.length(); i++)
    {
        n = n * 10 + (str[i] - '0');
    }

    if (n < 2)
        return false;

    bool flag = true;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void solve(int n, string str)
{
    //cout << n << " " << str << "\n";
    if (n == N)
    {
        cout << str << "\n";
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        string now = str + char('0' + i);
        if (check(now.substr(0, n + 1)))
        {
            solve(n + 1, now);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    solve(0, "");
    return 0;
}
