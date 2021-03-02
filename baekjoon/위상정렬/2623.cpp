#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> edges[1001];
int degree[1001];
queue<int> q;
bool visited[1001];
vector<int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int x, y, z;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        for (int j = 0; j < x - 1; j++)
        {
            cin >> z;
            edges[y].push_back(z);
            degree[z]++;
            y = z;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
            visited[i] = true;
        }
    }

    int selected = 0;
    while (!q.empty())
    {
        x = q.front();
        q.pop();

        selected += 1;
        ans.push_back(x);

        for (int v : edges[x])
        {
            if (!visited[v])
            {
                degree[v]--;
                if (degree[v] == 0)
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    if (selected < N)
    {
        cout << "0\n";
    }
    else
    {
        for (int a : ans)
        {
            cout << a << "\n";
        }
    }

    return 0;
}
