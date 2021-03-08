#include <iostream>

using namespace std;
int N, M;
string board[500];
pair<int, int> p[501][501];
int sum[501][501];

pair<int, int> getp(int i, int j)
{
    if (p[i][j] == make_pair(i, j))
        return make_pair(i, j);

    if (p[p[i][j].first][p[i][j].second] == p[i][j])
        return p[i][j];

    sum[p[i][j].first][p[i][j].second] += sum[i][j];

    return p[i][j] = getp(p[i][j].first, p[i][j].second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        for (int j = 0; j < M; j++)
        {
            p[i][j] = make_pair(i, j);
            sum[i][j] = 1;
        }
    }

    p[N][M] = make_pair(N, M);

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {

            int nx, ny;
            if (board[x][y] == 'D')
            {
                nx = x + 1;
                ny = y;
            }
            else if (board[x][y] == 'U')
            {
                nx = x - 1;
                ny = y;
            }
            else if (board[x][y] == 'R')
            {
                nx = x;
                ny = y + 1;
            }
            else
            {
                nx = x;
                ny = y - 1;
            }

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (getp(x, y) != getp(nx, ny))
                {

                    if (getp(x, y) == make_pair(N, M))
                    {
                        sum[N][M] += sum[p[nx][ny].first][p[nx][ny].second];
                        p[p[nx][ny].first][p[nx][ny].second] = make_pair(N, M);
                    }
                    else if (getp(nx, ny) == make_pair(N, M))
                    {
                        sum[N][M] += sum[p[x][y].first][p[x][y].second];
                        p[p[x][y].first][p[x][y].second] = make_pair(N, M);
                    }
                    else
                    {
                        sum[p[nx][ny].first][p[nx][ny].second] += sum[p[x][y].first][p[x][y].second];
                        p[p[x][y].first][p[x][y].second] = make_pair(p[nx][ny].first, p[nx][ny].second);
                    }
                }
            }
            else
            {
                if (getp(x, y) != make_pair(N, M))
                {
                    sum[N][M] += sum[p[x][y].first][p[x][y].second];
                    p[p[x][y].first][p[x][y].second] = make_pair(N, M);
                }
            }
        }
    }

    cout << sum[N][M] << "\n";
    return 0;
}
