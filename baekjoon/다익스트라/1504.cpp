#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, E;
int node1, node2;

#define INF 1999999999
vector<pair<int, int> > edges[801];

vector<int> dijkstra(int s, int N)
{
    vector<int> dist(N + 1);
    fill(dist.begin(), dist.end(), INF);
    priority_queue<pair<int, int> > pq;
    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < d)
            continue;

        for (pair<int, int> e : edges[now])
        {
            int next = e.second;
            int c = e.first;
            if (dist[now] == INF)
                continue;

            if (dist[next] > dist[now] + c)
            {
                dist[next] = dist[now] + c;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    return dist;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({z, y});
        edges[y].push_back({z, x});
    }
    cin >> node1 >> node2;

    vector<int> dist = dijkstra(1, N);
    vector<int> dist1 = dijkstra(node1, N);
    vector<int> dist2 = dijkstra(node2, N);

    long long ans = (long long)dist[node1] + dist1[node2] + dist2[N];
    ans = min(ans, (long long)dist[node2] + dist2[node1] + dist1[N]);

    if (ans >= INF)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }

    return 0;
}
