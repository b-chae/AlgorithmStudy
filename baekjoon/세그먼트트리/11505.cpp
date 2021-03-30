#include <iostream>
#include <cmath>

using namespace std;

int N, M, K;

int seg[4000000];
int A[1000001];

int init(int node, int start, int end)
{
    if (start > N)
        return 1;
    if (start == end)
        return seg[node] = A[start];
    int middle = (start + end) / 2;
    return seg[node] =
               (long long)init(node * 2, start, middle) * init(node * 2 + 1, middle + 1, end) % 1000000007;
}

int find(int node, int left, int right, int start, int end)
{
    if (start >= left && end <= right)
        return seg[node];
    if (start > right || end < left)
        return 1;

    int middle = (start + end) / 2;

    return (long long)find(node * 2, left, right, start, middle) * find(node * 2 + 1, left, right, middle + 1, end) % 1000000007;
}

int rebuild(int node, int start, int end, int index, int n)
{
    if (start > N || index < start || end < index)
        return seg[node];

    if (start == end && index == start)
        return seg[node] = n;

    int middle = (start + end) / 2;
    return seg[node] = (long long)rebuild(node * 2, start, middle, index, n) * rebuild(node * 2 + 1, middle + 1, end, index, n) % 1000000007;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    init(1, 1, pow(2, ceil(log2(N))));
    int x, y, z;

    for (int i = 0; i < M + K; i++)
    {
        cin >> x >> y >> z;
        if (x == 1)
        {
            rebuild(1, 1, pow(2, ceil(log2(N))), y, z);
        }
        else
        {
            cout << find(1, y, z, 1, pow(2, ceil(log2(N)))) << "\n";
        }
    }

    return 0;
}
