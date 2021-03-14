#include <iostream>
#include <queue>

using namespace std;

int p[1001];
int selected = 0;
int ans = 0;

priority_queue<pair<int, pair<int, int> > > pq;

int find(int n)
{
    if (p[n] == n)
        return n;
    return p[n] = find(p[n]);
}

void Union(int x, int y)
{
    if (x > y)
        swap(x, y);

    p[y] = x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i <= N; i++)
    {
        p[i] = i;
    }

    int x, y, z;
    for (int i = 0; i < K; i++)
    {
        cin >> x;
        p[x] = 0;
        if (i != K - 1)
            selected++;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        pq.push(make_pair(-z, make_pair(x, y)));
    }

    while (selected < N - 1)
    {
        int w = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();

        if (find(x) != find(y))
        {
            Union(p[x], p[y]);
            selected++;
            ans += w;
        }
    }

    cout << ans << "\n";

    return 0;
}
