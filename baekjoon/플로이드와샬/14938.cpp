#include <iostream>

using namespace std;

int N, M, R;
int item[101];

#define INF 3000
int d[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++)
    {
        cin >> item[i];
        for (int j = 1; j <= N; j++)
        {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }

    int x, y, z;

    for (int i = 0; i < R; i++)
    {
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
        d[y][x] = min(d[y][x], z);
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        int temp = 0;
        for (int j = 1; j <= N; j++)
        {
            if (d[i][j] <= M)
            {
                temp += item[j];
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << "\n";

    return 0;
}
