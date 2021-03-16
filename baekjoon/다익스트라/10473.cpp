#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define INF 3000000

double sx, sy, ex, ey;
int N;

int main()
{
    cin >> sx >> sy >> ex >> ey;
    cin >> N;
    N += 2;

    vector<pair<double, double> > loc(N + 1);
    vector<double> dist(N + 1);
    fill(dist.begin(), dist.end(), INF);

    loc[1] = make_pair(sx, sy);
    loc[N] = make_pair(ex, ey);

    for (int i = 0; i < N - 2; i++)
    {
        cin >> sx >> sy;
        loc[i + 2] = make_pair(sx, sy);
    }

    dist[1] = 0.0;
    priority_queue<pair<double, int> > pq;
    pq.push(make_pair(0.0, 1));

    while (!pq.empty())
    {
        double d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < d)
            continue;

        for (int next = 1; next <= N; next++)
        {
            bool flag = false;
            double x = sqrt(pow(loc[now].first - loc[next].first, 2) + pow(loc[now].second - loc[next].second, 2));
            double y = x / 5;

            if (d + y < dist[next])
            {
                dist[next] = d + y;
                flag = true;
            }

            if (now != 1 && now != N)
            {
                if (x >= 50)
                {
                    y = (x - 50) / 5 + 2;
                    if (d + y < dist[next])
                    {
                        dist[next] = d + y;
                        flag = true;
                    }
                }
                else
                {
                    y = (50 - x) / 5 + 2;
                    if (d + y < dist[next])
                    {
                        dist[next] = d + y;
                        flag = true;
                    }
                }
            }

            if (flag)
            {
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    cout << dist[N] << "\n";

    return 0;
}
