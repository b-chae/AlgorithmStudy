#include <iostream>

using namespace std;

int N, K;
long long D[201][201];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    int i, j, k;
    for (i = 1; i <= K; i++)
    {
        D[0][i] = 1;
    }
    for (i = 1; i <= N; i++)
    {
        D[i][1] = 1;
    }

    for (i = 1; i <= N; i++)
    {
        for (j = 2; j <= K; j++)
        {
            D[i][j] = (D[i - 1][j] + D[i][j - 1]) % 1000000000;
        }
    }

    cout << D[N][K] << "\n";
    return 0;
}
