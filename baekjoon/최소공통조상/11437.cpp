#include <iostream>
#include <vector>

using namespace std;

int N, T;

vector<int> edges[50001];
int depth[50001];
bool visited[50001];
int lca[50001][16];

void dfs(int n, int d, int pre)
{
    visited[n] = true;
    depth[n] = d;
    lca[n][0] = pre;

    for (int v : edges[n])
    {
        if (!visited[v])
        {
            dfs(v, d + 1, n);
        }
    }
}

void buildlca()
{
    for (int j = 1; j < 16; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
        }
    }
}

int getlca(int x, int y)
{
    if (depth[x] > depth[y])
    {
        swap(x, y);
    }

    for (int i = 15; i >= 0; i--)
    {
        if (depth[y] - depth[x] >= (1 << i))
        {
            y = lca[y][i];
        }
    }

    if (x == y)
        return x;

    for (int i = 15; i >= 0; i--)
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

    cin >> N;

    int x, y, i;

    for (i = 0; i < N - 1; i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(1, 1, 0);
    buildlca();

    cin >> T;

    for (i = 0; i < T; i++)
    {
        cin >> x >> y;
        cout << getlca(x, y) << "\n";
    }

    return 0;
}
