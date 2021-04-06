#include <iostream>
#include <cmath>

using namespace std;

int N, K;
int A[100001];
int seg[400002];

int get101(int n)
{
    if (n > 0)
        return 1;
    else if (n < 0)
        return -1;
    return 0;
}

int init(int node, int left, int right)
{
    if (left > N)
        return 1;
    if (left == right)
        return seg[node] = get101(A[left]);

    int middle = (left + right) / 2;
    return seg[node] = init(node * 2, left, middle) * init(node * 2 + 1, middle + 1, right);
}

int change(int node, int left, int right, int index, int n)
{
    if (left > index || right < index)
        return seg[node];

    if (left == right)
    {
        return seg[node] = get101(n);
    }

    int middle = (left + right) / 2;
    return seg[node] = change(node * 2, left, middle, index, n) * change(node * 2 + 1, middle + 1, right, index, n);
}

int getseg(int node, int left, int right, int start, int end)
{
    if (left > end || right < start)
        return 1;
    if (left >= start && right <= end)
        return seg[node];
    int middle = (left + right) / 2;
    return getseg(node * 2, left, middle, start, end) * getseg(node * 2 + 1, middle + 1, right, start, end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;

    while (cin >> N >> K)
    {
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
        }

        init(1, 1, pow(2, ceil(log2(N))));

        for (int i = 0; i < K; i++)
        {
            char c;
            cin >> c;
            if (c == 'C')
            {
                cin >> x >> y;
                change(1, 1, pow(2, ceil(log2(N))), x, y);
            }
            else
            {
                cin >> x >> y;
                int a = getseg(1, 1, pow(2, ceil(log2(N))), x, y);
                if (a == 1)
                    cout << "+";
                else if (a == 0)
                    cout << "0";
                else
                    cout << "-";
            }
        }

        cout << "\n";
    }

    return 0;
}
