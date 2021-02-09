#include <iostream>
#include <vector>

using namespace std;

int N, M;
int depth[40001];
vector<pair<int, int> > edges[40001];
int lca[40001][18];
int dist[40001][18];
bool visited[40001];

void dfs(int n, int d, int pre, int predist)
{
    visited[n] = true;
    depth[n] = d;
    lca[n][0] = pre;
    dist[n][0] = predist;

    for (pair<int, int> v : edges[n])
    {
        if (!visited[v.second])
        {
            dfs(v.second, d + 1, n, v.first);
        }
    }
}

void build_lca()
{
    int i, j;
    for (j = 1; j < 18; j++)
    {
        for (i = 1; i <= N; i++)
        {
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
            dist[i][j] = dist[i][j - 1] + dist[lca[i][j - 1]][j - 1];
        }
    }
}

int getlca(int x, int y)
{
    int ans = 0;

    if (depth[x] > depth[y])
    {
        swap(x, y);
    }

    for (int i = 17; i >= 0; i--)
    {
        if (depth[y] - depth[x] >= (1 << i))
        {
            ans += dist[y][i];
            y = lca[y][i];
        }
    }

    if (x == y)
        return ans;

    for (int i = 17; i >= 0; i--)
    {
        if (lca[x][i] != lca[y][i])
        {
            ans += dist[x][i] + dist[y][i];
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    return ans + dist[x][0] + dist[y][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int x, y, z, i;

    for (i = 0; i < N - 1; i++)
    {
        cin >> x >> y >> z;
        edges[x].push_back({z, y});
        edges[y].push_back({z, x});
    }

    dfs(1, 1, 0, 0);
    build_lca();

    cin >> M;

    for (i = 0; i < M; i++)
    {
        cin >> x >> y;
        cout << getlca(x, y) << "\n";
    }

    return 0;
}
