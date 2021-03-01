#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> edges[100001];
bool visited[100001];
int depth[100001];
int lca[100001][18];

void dfs(int n, int d, int p)
{
    visited[n] = true;
    depth[n] = d;
    lca[n][0] = p;

    for (int v : edges[n])
    {
        if (!visited[v])
        {
            dfs(v, d + 1, n);
        }
    }
}

void build_lca()
{
    for (int j = 1; j < 18; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
    }
}

int find_lca(int x, int y)
{
    if (depth[x] > depth[y])
    {
        swap(x, y);
    }

    for (int i = 17; i >= 0; i--)
    {
        if (depth[y] >= depth[x] + (1 << i))
        {
            y = lca[y][i];
        }
    }

    if (x == y)
        return x;

    for (int i = 17; i >= 0; i--)
    {
        if (lca[x][i] != lca[y][i])
        {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    return lca[x][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int i;
    int x, y, z;
    for (i = 0; i < N - 1; i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(1, 0, 0);
    build_lca();

    cin >> M;
    for (i = 0; i < M; i++)
    {
        cin >> x >> y >> z;

        int lca1 = find_lca(x, y);
        int lca2 = find_lca(x, z);
        int lca3 = find_lca(y, z);

        int ans = lca1;
        if (depth[lca2] > depth[ans])
            ans = lca2;
        if (depth[lca3] > depth[ans])
            ans = lca3;

        cout << ans << "\n";
    }
    return 0;
}
