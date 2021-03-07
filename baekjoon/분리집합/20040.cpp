#include <iostream>

using namespace std;

int N, M;
int p[500000];

int getp(int n)
{
    if (p[n] == n)
        return n;
    return p[n] = getp(p[n]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int x, y;
    bool flag = false;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        if (getp(x) != getp(y))
        {
            p[p[x]] = p[y];
        }
        else if (!flag)
        {
            flag = true;
            ans = i + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
