#include <iostream>

using namespace std;

int T, N;
long long D[31][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {

        cin >> N;

        if (N == 0)
            break;

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                D[i][j] = 0;
            }
        }

        D[0][N] = 1;

        for (int j = N - 1; j >= 0; j--)
        {
            for (int i = N; i >= 0; i--)
            {
                if (i - 1 >= 0)
                {
                    D[i][j] += D[i - 1][j + 1];
                }
                if (i + 1 <= N)
                {
                    D[i][j] += D[i + 1][j];
                }
            }
        }

        cout << D[0][0] << "\n";
    }

    return 0;
}
