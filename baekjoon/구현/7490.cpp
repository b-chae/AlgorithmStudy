#include <iostream>
#include <string>

using namespace std;

int T, N;

void solve(int n, string s)
{
    if (n == N)
    {
        int a = 0, pre = 0;
        char c = '+';
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                pre = pre * 10 + s[i] - '0';
            }
            else if (s[i] != ' ')
            {
                if (c == '+')
                    a = a + pre;
                else
                    a = a - pre;

                c = s[i];
                pre = 0;
            }
        }
        if (c == '+')
            a = a + pre;
        else
            a = a - pre;
        if (a == 0)
            cout << s << "\n";

        return;
    }
    solve(n + 1, s + " " + to_string(n + 1));
    solve(n + 1, s + "+" + to_string(n + 1));
    solve(n + 1, s + "-" + to_string(n + 1));
}

int main()
{
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        solve(1, "1");
        cout << "\n";
    }
    return 0;
}
