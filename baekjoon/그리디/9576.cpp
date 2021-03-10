#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
    int start, end;

    bool operator<(const node &a) const
    {
        if (end == a.end)
        {
            return start > a.start;
        }

        return end > a.end;
    }
} node;

int T, N, M;
bool check[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;

    int x, y;
    for (int t = 0; t < T; t++)
    {
        priority_queue<node> pq;
        cin >> N >> M;
        for (int i = 0; i <= N; i++)
        {
            check[i] = false;
        }

        for (int i = 0; i < M; i++)
        {
            cin >> x >> y;
            pq.push({x, y});
        }

        int answer = 0;
        while (!pq.empty())
        {
            x = pq.top().start;
            y = pq.top().end;
            pq.pop();

            for (int i = x; i <= y; i++)
            {
                if (!check[i])
                {
                    check[i] = true;
                    answer++;
                    break;
                }
            }
        }
        cout << answer << "\n";
    }

    return 0;
}
