#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int degree[101];
vector<pair<int, int> > edges[101];
queue<int> q;
bool visited[101];
int ans[101];
int N, M;

int main()
{
    ios::sync_with_stdio(0);

    cin >> N >> M;
    int x, y, z;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        degree[y]++;
        edges[x].push_back({z, y});
    }

    ans[N] = 1;
    visited[N] = true;
    q.push(N);

    while (!q.empty())
    {
        x = q.front();
        q.pop();

        if (edges[x].empty())
            continue;

        for (pair<int, int> vertex : edges[x])
        {
            int c = vertex.first;
            int v = vertex.second;
            if (!visited[v])
            {
                degree[v]--;
                if (degree[v] == 0)
                {
                    visited[v] = true;
                    q.push(v);
                }
                ans[v] += ans[x] * c;
            }
        }

        ans[x] = 0;
    }

    for (int i = 1; i <= N; i++)
    {
        if (ans[i] != 0)
        {
            cout << i << " " << ans[i] << "\n";
        }
    }

    return 0;
}
