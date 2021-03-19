#include <iostream>

using namespace std;

int N, M, K;
int A[100][100];

int[][] spin(int[][] A, int x, int y, int z)
{
    int temp[100][100];
    for (int k = z; k >= 0; k--)
    {
        for (int j = y - k + 1; j <= y + k; j++)
        {
            temp[x - k][j] = A[x - k][j - 1];
        }

        for (int i = x - k + 1; i <= x + k; i++)
        {
            temp[i][y + k] = A[i - 1][y + k];
        }

        for (int j = y - k; j < y + k; j++)
        {
            temp[x + k][j] = A[x + k][j + 1];
        }

        for (int i = x - k; i < x + k; i++)
        {
            temp[i][y - k] = A[i + 1][y - k];
        }
    }

    temp[x][y] = A[x][y];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i < x - z || i > x + z || j < y - z || j > y + z)
            {
                temp[i][j] = A[i][j];
            }
        }
    }
    return temp;
}

int get_sum(int[][] temp)
{

    int res = 200000;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < M; j++)
        {
            sum += temp[i][j];
        }
        res = min(res, sum);
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    int x, y, z;
    int ans = 2000000;

    for (int i = 0; i < K; i++)
    {
        cin >> x >> y >> z;
    }

    cout << ans << "\n";

    return 0;
}
