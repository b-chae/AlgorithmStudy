#include <iostream>
#include <vector>

using namespace std;

#define INF 2500

int N;
int d[51][51];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int x, y;

    for (x = 1; x <= N; x++)
    {
        for (y = 1; y <= N; y++)
        {
            d[x][y] = INF;
        }
        d[x][x] = 0;
    }

    while (true)
    {
        cin >> x >> y;
        if (x == -1 && y == -1)
        {
            break;
        }

        d[x][y] = 1;
        d[y][x] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (x = 1; x <= N; x++)
        {
            for (y = 1; y <= N; y++)
            {
                if (d[x][y] > d[x][k] + d[k][y])
                {
                    d[x][y] = d[x][k] + d[k][y];
                }
            }
        }
    }

    int minscore = INF;
    vector<int> ans;

    for (x = 1; x <= N; x++)
    {
        int nowmax = 0;
        for (y = 1; y <= N; y++)
        {
            nowmax = max(d[x][y], nowmax);
        }
        if (nowmax < minscore)
        {
            minscore = nowmax;
            ans.clear();
            ans.push_back(x);
        }
        else if (nowmax == minscore)
        {
            ans.push_back(x);
        }
    }

    cout << minscore << " " << ans.size() << "\n";
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}
