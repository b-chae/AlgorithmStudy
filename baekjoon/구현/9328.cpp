#include <iostream>
#include <queue>

using namespace std;

int T, N, M;
string board[100];
bool visited[100][100][27];
bool key[26];

int count_key()
{
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        if (key[i])
            res++;
    }
    return res;
}

void check_boundary(queue<pair<pair<int, int>, int> > &q)
{
    int ihave = count_key();
    for (int i = 0; i < N; i++)
    {
        if (board[i][0] != '*' && !visited[i][0][ihave])
        {
            q.push(make_pair(make_pair(i, 0), ihave));
            visited[i][0][ihave] = true;
        }
        if (board[i][M - 1] != '*' && !visited[i][M - 1][ihave])
        {
            q.push(make_pair(make_pair(i, M - 1), ihave));
            visited[i][M - 1][ihave] = true;
        }
    }

    for (int i = 1; i < M - 1; i++)
    {
        if (board[0][i] != '*' && !visited[0][i][ihave])
        {
            q.push(make_pair(make_pair(0, i), ihave));
            visited[0][i][ihave] = true;
        }
        if (board[N - 1][i] != '*' && !visited[N - 1][i][ihave])
        {
            q.push(make_pair(make_pair(N - 1, i), ihave));
            visited[N - 1][i][ihave] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            cin >> board[i];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                for (int k = 0; k < 27; k++)
                {
                    visited[i][j][k] = false;
                }
            }
        }
        for (int k = 0; k < 26; k++)
        {
            key[k] = false;
        }

        string k;
        cin >> k;
        if (k[0] != '0')
        {
            for (int i = 0; i < k.length(); i++)
            {
                key[k[i] - 'a'] = true;
            }
        }

        queue<pair<pair<int, int>, int> > q;
        check_boundary(q);
        int ans = 0;

        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int k = q.front().second;
            q.pop();

            if (board[x][y] == '$')
            {
                ans++;
                board[x][y] = '.';
            }
            if (board[x][y] >= 'a' && board[x][y] <= 'z' && !key[board[x][y] - 'a'])
            {
                key[board[x][y] - 'a'] = true;
            }
            if (board[x][y] >= 'A' && board[x][y] <= 'Z' && !key[board[x][y] - 'A'])
                continue;

            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < M && board[nx][ny] != '*')
                {
                    if (!visited[nx][ny][count_key()])
                    {
                        q.push(make_pair(make_pair(nx, ny), count_key()));
                        visited[nx][ny][count_key()] = true;
                    }
                }
            }
            check_boundary(q);
        }

        cout << ans << "\n";
    }
    return 0;
}
