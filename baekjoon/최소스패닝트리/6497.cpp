#include <iostream>
#include <queue>

using namespace std;

int p[200001];

struct node
{
    long long w;
    int x, y;

    bool operator<(const node &a) const
    {
        return w > a.w;
    }
};

int find(int n)
{
    if (n == p[n])
        return n;
    return p[n] = find(p[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, x, y;
    long long z;

    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            p[i] = i;
        }

        long long total = 0;
        priority_queue<node> pq;

        for (int i = 0; i < M; i++)
        {
            cin >> x >> y >> z;
            total += z;
            node new_node;
            new_node.w = z;
            new_node.x = x;
            new_node.y = y;
            pq.push(new_node);
        }

        int selected = 0;
        long long select = 0;

        while (selected < N - 1)
        {
            node top = pq.top();
            pq.pop();

            if (find(top.x) != find(top.y))
            {
                select += top.w;
                selected++;
                p[p[top.x]] = p[top.y];
            }
        }

        cout << total - select << "\n";
    }

    return 0;
}
