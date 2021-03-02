#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
priority_queue<int> pq;
vector<int> edges[32001];
int degree[32001];
bool visited[32001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int x, y;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
        degree[y]++;
    }

    int selected = 0;

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i] && degree[i] == 0)
        {
            pq.push(-i);
            visited[i] = true;
        }
    }

    while (selected < N)
    {
        int t = -pq.top();
        pq.pop();

        cout << t << " ";
        selected++;

        for (int v : edges[t])
        {
            degree[v]--;
            if (!visited[v] && degree[v] == 0)
            {
                pq.push(-v);
                visited[v] = true;
            }
        }
    }

    return 0;
}
