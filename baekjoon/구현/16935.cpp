#include <iostream>

using namespace std;
int N, M, R;
int A[100][100];

void turn(int n)
{
    int temp[100][100];
    if (n == 1)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                temp[N - 1 - j][i] = A[j][i];
            }
        }
    }
    else if (n == 2)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                temp[i][M - 1 - j] = A[i][j];
            }
        }
    }
    else if (n == 3)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                temp[j][N - i - 1] = A[i][j];
            }
        }
        swap(N, M);
    }
    else if (n == 4)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                temp[M - 1 - j][i] = A[i][j];
            }
        }
        swap(N, M);
    }
    else if (n == 5)
    {
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                temp[i][j] = A[i + N / 2][j];
            }
        }
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = M / 2; j < M; j++)
            {
                temp[i][j] = A[i][j - M / 2];
            }
        }
        for (int i = N / 2; i < N; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                temp[i][j] = A[i][j + M / 2];
            }
        }
        for (int i = N / 2; i < N; i++)
        {
            for (int j = M / 2; j < M; j++)
            {
                temp[i][j] = A[i - N / 2][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                temp[i][j] = A[i][j + M / 2];
            }
        }
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = M / 2; j < M; j++)
            {
                temp[i][j] = A[i + N / 2][j];
            }
        }
        for (int i = N / 2; i < N; i++)
        {
            for (int j = 0; j < M / 2; j++)
            {
                temp[i][j] = A[i - N / 2][j];
            }
        }
        for (int i = N / 2; i < N; i++)
        {
            for (int j = M / 2; j < M; j++)
            {
                temp[i][j] = A[i][j - M / 2];
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = temp[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        int x;
        cin >> x;
        turn(x);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
