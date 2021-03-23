#include <iostream>

using namespace std;

int N, M;
int A[500];
bool rain[500][500];
int ans;

void check(int i, int j)
{
    bool left = false, right = false;

    for (int y = j - 1; y >= 0; y--)
    {
        if (A[y] - 1 >= i)
        {
            left = true;
            break;
        }
    }
    for (int y = j + 1; y < M; y++)
    {
        if (A[y] - 1 >= i)
        {
            right = true;
            break;
        }
    }

    if (left && right)
    {
        rain[i][j] = true;
        ans++;
        cout << i << " " << j << " " << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[j] > i)
                continue;

            if (i == 0 || rain[i - 1][j] || A[j] == i)
            {
                check(i, j);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
