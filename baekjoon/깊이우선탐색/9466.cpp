#include <iostream>

using namespace std;

int T, N;
int p[100001];
bool visited[100001];
bool done[100001];
int ans;

void dfs(int n)
{
    visited[n] = true;

    int next = p[n];
    if (!visited[next])
    {
        dfs(next);
    }
    else if (!done[next])
    {
        for (int i = next; i != n; i = p[i])
        {
            ans++;
        }
        ans++;
    }
    done[n] = true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        ans = 0;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> p[i];
            visited[i] = false;
            done[i] = false;
        }

        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
                dfs(i);
        }
        cout << N - ans << "\n";
    }
    return 0;
}
