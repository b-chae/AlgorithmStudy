#include <iostream>

using namespace std;
int T, N, K;
int D[101][101][2];

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> T;
    int i, j;
    for (t = 0; t < T; t++)
    {
        cin >> N >> K;
        for (i = 0; i <= N; i++)
        {
            for (j = 0; j <= K; j++)
            {
                D[i][j][0] = 0;
                D[i][j][1] = 0;
            }
        }

        D[1][0][0] = 1;
        D[1][0][1] = 1;

        for (i = 2; i <= N; i++)
        {
            D[i][0][1] = D[i - 1][0][0];
            D[i][0][0] = D[i - 1][0][0] + D[i - 1][0][1];
        }

        for (i = 2; i <= N; i++)
        {
            for (j = 1; j <= K; j++)
            {
                D[i][j][0] = D[i - 1][j][0] + D[i - 1][j][1];
                D[i][j][1] = D[i - 1][j - 1][1] + D[i - 1][j][0];
            }
        }

        cout << D[N][K][0] + D[N][K][1] << "\n";
    }

    return 0;
}
