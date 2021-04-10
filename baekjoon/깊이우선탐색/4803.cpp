#include <iostream>
#include <vector>

using namespace std;
bool visited[501];
int N, M;
vector<int> adj[501];

bool dfs(int n, int pre)
{
    visited[n] = true;

    for (int next : adj[n])
    {
        if (pre == next)
            continue;

        if (visited[next])
            return false;
        if (dfs(next, n) == false)
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    while (true)
    {
        t++;
        int tree = 0;
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        for (int i = 1; i <= N; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }

        int x, y;
        for (int i = 0; i < M; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, 0))
                    tree++;
            }
        }
        cout << "Case " << t << ": ";
        if (tree == 0)
            cout << "No trees.\n";
        else if (tree == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << tree << " trees.\n";
    }
    return 0;
}
