#include <iostream>
#include <queue>

using namespace std;

int A[20][20];
int N;
int sx, sy;
int ans = 0;
int ssize = 2;
int scount = 0;

struct node
{
    int x, y, move;

    bool operator<(const node &a) const
    {
        if (move == a.move)
        {
            if (x == a.x)
            {
                return y > a.y;
            }
            return x > a.x;
        }
        return move > a.move;
    }
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve()
{
    while (true)
    {
        queue<node> search;
        priority_queue<node> find;
        bool visited[400];
        fill(visited, visited + 400, 0);

        search.push({sx, sy, 0});
        visited[sx * N + sy] = true;
        while (!search.empty())
        {
            int x = search.front().x;
            int y = search.front().y;
            int move = search.front().move;
            search.pop();

            if (A[x][y] > 0 && A[x][y] < ssize)
            {
                find.push({x, y, move});
                continue;
            }

            if (!find.empty() && find.top().move < move + 1)
            {
                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx * N + ny] && A[nx][ny] <= ssize)
                {
                    search.push({nx, ny, move + 1});
                    visited[nx * N + ny] = true;
                }
            }
        }

        if (!find.empty())
        {
            sx = find.top().x;
            sy = find.top().y;
            scount++;
            if (scount == ssize)
            {
                ssize++;
                scount = 0;
            }

            A[sx][sy] = 0;
            ans += find.top().move;
            cout << sx << " " << sy << " " << ans << "\n";
        }
        else
        {
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 9)
            {
                sx = i;
                sy = j;
                A[i][j] = 0;
            }
        }
    }

    int x;

    solve();

    cout << ans << "\n";

    return 0;
}
