#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
    int n;
    int c;

    bool operator<(const node &a) const
    {
        return c > a.c;
    }
} node;

int N, M, K;
int P[10001];
int A[10001];
priority_queue<node> pq;

int findP(int n)
{
    if (P[n] == n)
    {
        return n;
    }

    if (P[P[n]] == P[n])
    {
        return P[n];
    }

    A[P[n]] += A[n];

    return findP(P[n]);
}

void Union(int x, int y)
{
    x = findP(x);
    y = findP(y);

    if (x == y)
        return;

    if (x < y)
    {
        swap(x, y);
    }

    A[y] += A[P[x]];
    P[P[x]] = P[y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        pq.push({i, x});
        P[i] = i;
        A[i] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        Union(x, y);
    }

    int ans = 0;

    while (A[0] < N && ans < K && !pq.empty())
    {
        node top = pq.top();
        pq.pop();
        if (findP(top.n) != 0)
        {
            Union(0, top.n);
            ans += top.c;
        }
    }

    if (A[0] != N || ans > K)
    {
        cout << "Oh no\n";
    }
    else
    {
        cout << ans << "\n";
    }

    return 0;
}
