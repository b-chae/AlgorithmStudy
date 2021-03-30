#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, S;
int A[501];
int degree[501];
bool edge[501][501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i <= N; i++)
        {
            degree[i] = 0;
            for (int j = 0; j <= N; j++)
            {
                edge[i][j] = false;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                degree[A[j]]++;
                edge[A[i]][A[j]] = true;
            }
        }
        cin >> S;
        int x, y;
        for (int i = 0; i < S; i++)
        {
            cin >> x >> y;
            if (edge[x][y])
            {
                degree[y]--;
                degree[x]++;
                edge[x][y] = false;
                edge[y][x] = true;
            }
            else if (edge[y][x])
            {
                degree[x]--;
                degree[y]++;
                edge[y][x] = false;
                edge[x][y] = true;
            }
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= N; i++)
        {
            if (degree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            if (q.size() >= 2)
            {
                break;
            }

            x = q.front();
            q.pop();
            ans.push_back(x);

            for (int i = 1; i <= N; i++)
            {
                if (edge[x][i])
                {
                    edge[x][i] = false;
                    degree[i]--;
                    if (degree[i] == 0)
                    {
                        q.push(i);
                    }
                }
            }
        }

        if (ans.size() == N)
        {
            for (int a : ans)
            {
                cout << a << " ";
            }
            cout << "\n";
        }
        else if (q.size() >= 2)
        {
            cout << "?\n";
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
