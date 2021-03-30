#include <iostream>
#include <queue>
#include <set>

using namespace std;
int A, B, C, D;

struct node
{
    int a, b, d;
};

set<int> visited[100010];
queue<node> bfsQueue;

bool isVisited(int x, int y)
{
    if (visited[x].find(y) == visited[x].end())
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C >> D;
    bfsQueue.push({0, 0, 0});
    visited[0].insert(0);

    while (!bfsQueue.empty())
    {
        int a = bfsQueue.front().a;
        int b = bfsQueue.front().b;
        int d = bfsQueue.front().d;
        bfsQueue.pop();

        if (a == C && b == D)
        {
            cout << d << "\n";
            return 0;
        }

        if (a != A && !isVisited(A, b))
        {
            bfsQueue.push({A, b, d + 1});
            visited[A].insert(b);
        }
        if (b != B && !isVisited(a, B))
        {
            bfsQueue.push({a, B, d + 1});
            visited[a].insert(B);
        }
        if (a != 0 && !isVisited(0, b))
        {
            bfsQueue.push({0, b, d + 1});
            visited[0].insert(b);
        }
        if (b != 0 && !isVisited(a, 0))
        {
            bfsQueue.push({a, 0, d + 1});
            visited[a].insert(0);
        }
        int x = min(A, a + b);
        int y = max((a + b - A), 0);
        if (x != a && y != b && !isVisited(x, y))
        {
            bfsQueue.push({x, y, d + 1});
            visited[x].insert(y);
        }
        x = min(B, a + b);
        y = max((a + b - B), 0);
        if (x != b && y != a && !isVisited(y, x))
        {
            bfsQueue.push({y, x, d + 1});
            visited[y].insert(x);
        }
    }

    cout << "-1\n";

    return 0;
}
