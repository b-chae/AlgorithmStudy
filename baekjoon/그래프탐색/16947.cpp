#include <iostream>
#include <vector>

using namespace std;

vector<int> edges[3001];
int N;
bool visited[3001];
bool cycle[3001];

void init()
{
    for (int i = 1; i <= N; i++)
    {
        visited[i] = false;
    }
}

void check(int n, int start, int d)
{
    visited[start] = true;
    for (int v : edges[start])
    {
        if (v == n && d > 1)
        {
            cycle[n] = true;
            return;
        }
        if (!visited[v])
        {
            check(n, v, d + 1);
        }
    }
}

int solve(int n, int r)
{
    visited[n] = true;
    if (cycle[n])
        return 0;

    r = 100000000;
    for (int v : edges[n])
    {
        if (!visited[v])
            r = min(r, solve(v, r) + 1);
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        init();
        check(i, i, 0);
    }

    for (int i = 1; i <= N; i++)
    {
        init();
        cout << solve(i, 0) << " ";
    }

    return 0;
}
