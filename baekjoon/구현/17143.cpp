#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int bd[4] = {1, 0, 3, 2};

struct shark
{
    int x, y, speed, dir, size;
    bool live;
};

int N, M, S;
int ans = 0;

void catch_shark(int here, vector<shark> &myshark)
{

    int x = 200;
    int index = -1;

    for (int i = 0; i < myshark.size(); i++)
    {
        if (myshark[i].live && here == myshark[i].y && myshark[i].x < x)
        {
            index = i;
            x = myshark[i].x;
        }
    }

    if (index != -1)
    {
        ans += myshark[index].size;
        myshark[index].live = false;
    }
}

void shark_move(vector<shark> &myshark)
{
    int temp[100][100];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            temp[i][j] = -1;
        }
    }

    for (int i = 0; i < myshark.size(); i++)
    {
        if (!myshark[i].live)
            continue;

        int x = myshark[i].x;
        int y = myshark[i].y;
        int dir = myshark[i].dir;
        int speed = myshark[i].speed;

        int nx = x + dx[dir] * speed;
        int ny = y + dy[dir] * speed;

        while (nx < 0 || nx >= N)
        {
            dir = bd[dir];
            if (nx < 0)
                nx *= -1;
            else
                nx = 2 * N - nx - 2;
        }
        while (ny < 0 || ny >= M)
        {
            dir = bd[dir];
            if (ny < 0)
                ny *= -1;
            else
                ny = 2 * M - ny - 2;
        }

        myshark[i].dir = dir;
        myshark[i].x = nx;
        myshark[i].y = ny;

        //cout << "!" << i << " " << myshark[i].x << " " << myshark[i].y << " " << myshark[i].dir << "\n";

        if (temp[nx][ny] == -1)
        {
            temp[nx][ny] = i;
        }
        else
        {
            int there = temp[nx][ny];
            if (!myshark[there].live)
            {
                temp[nx][ny] = i;
            }
            else if (myshark[there].size < myshark[i].size)
            {
                myshark[there].live = false;
                temp[nx][ny] = i;
            }
            else
            {
                myshark[i].live = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> S;

    vector<shark> myshark;

    for (int i = 0; i < S; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        myshark.push_back({r - 1, c - 1, s, d - 1, z, true});
    }

    for (int move = 0; move < M; move++)
    {
        catch_shark(move, myshark);
        shark_move(myshark);

        for (int i = 0; i < myshark.size(); i++)
        {
            //cout << myshark[i].x << " " << myshark[i].y << " " << myshark[i].dir << " " << myshark[i].size << " " << myshark[i].speed << "\n";
        }
    }

    cout << ans << "\n";

    return 0;
}
