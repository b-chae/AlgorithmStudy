#include <iostream>

using namespace std;

long long D[65][10];
int T, N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> N;

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                D[i][j] = 0;
            }
        }
        for (int j = 0; j < 10; j++)
        {
            D[1][j] = 1;
        }

        for (int i = 2; i <= N; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k <= j; k++)
                {
                    D[i][j] += D[i - 1][k];
                }
            }
        }

        long long ans = 0;
        for (int j = 0; j < 10; j++)
        {
            ans += D[N][j];
        }
        cout << ans << "\n";
    }
    return 0;
}
