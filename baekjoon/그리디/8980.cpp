#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
    int end, cost;

    bool operator<(const node &a) const
    {
        if (end == a.end)
            return cost < a.cost;
        return end > a.end;
    }
} node;

int N, C, M;
priority_queue<node> pq[2001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C >> M;

    int x, y, z;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        pq[x].push({y, z});
    }

    int ans = 0;
    int now = 0;

    priority_queue<node> queue;

    for (int i = 1; i <= N; i++)
    {
        while (!queue.empty() && queue.top().end == i)
        {
            now -= queue.top().cost;
            ans += queue.top().cost;
            queue.pop();
        }

        while (!pq[i].empty() && now < C)
        {
            int e = pq[i].top().end;
            int c = pq[i].top().cost;

            int k = min(c, C - now);
            now += k;
            pq[i].pop();
            queue.push({e, k});
            cout << i << " " << e << " " << k << " " << ans << " " << now << "\n";
        }
    }

    cout << ans << "\n";
    return 0;
}
