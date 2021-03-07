#include <iostream>
#include <cmath>

using namespace std;

int T, N;
int p[20001];
int dist[20001];

int getP(int x)
{
    if (p[x] == x)
        return x;

    int t = getP(p[x]);
    dist[x] += dist[p[x]];
    return p[x] = t;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    char c;
    int x, y;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            dist[i] = 0;
            p[i] = i;
        }

        while (true)
        {
            cin >> c;
            if (c == 'O')
                break;

            if (c == 'E')
            {
                cin >> x;
                getP(x);
                cout << dist[x] << "\n";
            }
            else if (c == 'I')
            {
                cin >> x >> y;
                getP(x);
                getP(y);

                dist[x] += abs(x - y) % 1000;
                p[x] = y;
            }
        }
    }

    return 0;
}
