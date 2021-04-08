#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int A[101];
bool visited[101];
bool done[101];
vector<int> ans;

void dfs(int n)
{
    visited[n] = true;
    int next = A[n];
    if (!visited[next])
        dfs(next);

    else if (!done[next])
    {
        for (int i = next; i != n; i = A[i])
            ans.push_back(i);
        ans.push_back(n);
    }
    done[n] = true;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (int a : ans)
    {
        cout << a << "\n";
    }
    return 0;
}
