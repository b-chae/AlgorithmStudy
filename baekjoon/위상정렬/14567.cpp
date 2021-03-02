#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int degree[1001];
int ans[1001];
vector<int> edges[1001];
queue<int> q;
bool visited[1001];

int main()
{
    ios::sync_with_stdio(0);

    cin >> N >> M;

    int x, y;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
        degree[y]++;
    }

    int time = 1;
    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
            visited[i] = true;
            ans[i] = time;
        }
    }

    while (!q.empty())
    {
        x = q.front();
        q.pop();

        for (int v : edges[x])
        {
            if (!visited[v])
            {
                degree[v]--;
                if (degree[v] == 0)
                {
                    visited[v] = true;
                    q.push(v);
                    ans[v] = ans[x] + 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
