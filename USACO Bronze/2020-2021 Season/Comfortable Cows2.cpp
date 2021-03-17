#include <iostream>
#include <map>
#include <queue>

using namespace std;

bool dot[3000][3000];
int total_cow = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int> > q;

void evaluate(int x, int y)
{
    if (!dot[x][y])
        return;
    //cout << x << " " << y << "\n";
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (dot[nx][ny])
            count++;
    }

    if (count == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!dot[nx][ny])
            {
                q.push({nx, ny});
            }
        }
    }
}

void check_dot(int x, int y)
{
    q.push({x, y});
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (dot[x][y])
            continue;

        total_cow++;
        dot[x][y] = true;
        evaluate(x, y);
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            evaluate(nx, ny);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, x, y;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> x >> y;
        check_dot(x + 1000, y + 1000);
        cout << total_cow - i << "\n";
    }

    return 0;
}
