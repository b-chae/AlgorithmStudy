#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
unsigned int board[21];
int ans = 400;

void brute(int n)
{
    if (n == N)
    {
        int c = 0;
        for (int i = 0; i < N; i++)
        {
            int t = 0;
            int h = 0;
            for (int j = 0; j < N; j++)
            {
                if ((board[j] & (1 << i)) == (1 << i))
                    t++;
                else
                    h++;
            }
            t = min(h, t);
            c += t;
        }
        ans = min(ans, c);
        return;
    }

    board[n] = ~board[n];
    brute(n + 1);
    board[n] = ~board[n];
    brute(n + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string s;
    int i, j;
    for (i = 0; i < N; i++)
    {
        cin >> s;
        for (j = 0; j < N; j++)
        {
            if (s[j] == 'T')
                board[i] |= (1 << j);
        }
    }

    brute(0);
    cout << ans << "\n";

    return 0;
}
