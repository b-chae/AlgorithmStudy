#include <iostream>

using namespace std;

#define INF 10001

int N, M;
int d[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int i, j, x, y;

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }

    for (i = 0; i < M; i++)
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

    for (i = 1; i <= N; i++)
    {
        int count = 0;
        for (j = 1; j <= N; j++)
        {
            if (d[i][j] == INF && d[j][i] == INF)
            {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
