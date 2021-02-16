#include <iostream>

using namespace std;

int N;
int graph[20][20];
bool exclude[20][20];
int result;

void floyd()
{
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {

                if (i == j || j == k || i == k)
                {
                    continue;
                }
                else if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    result = -1;
                    return;
                }
                else if (graph[i][j] == graph[i][k] + graph[k][j])
                {
                    exclude[i][j] = true;
                }
            }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    floyd();

    if (result != -1)
    {

        for (int i = 0; i < N; i++)

            for (int j = 0; j < N; j++)

                if (!exclude[i][j])
                    result += graph[i][j];

        cout << result / 2 << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}
