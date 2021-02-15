#include <iostream>

using namespace std;

#define INF 1600000

int N, K, S;
int d[401][401];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    int i, j, x, y;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }

    for (i = 0; i < K; i++)
    {
        cin >> x >> y;
        d[x][y] = 1;
    }

    for (x = 1; x <= N; x++)
    {
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                if (d[i][j] > d[i][x] + d[x][j])
                {
                    d[i][j] = d[i][x] + d[x][j];
                }
            }
        }
    }

    cin >> S;

    for (i = 0; i < S; i++)
    {
        cin >> x >> y;
        if (d[x][y] < INF)
        {
            cout << "-1\n";
        }
        else if (d[y][x] < INF)
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }

    return 0;
}
