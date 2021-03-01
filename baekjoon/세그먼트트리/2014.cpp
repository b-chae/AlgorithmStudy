#include <iostream>
#include <cmath>

using namespace std;

int N;
long long A[100001];
int seg[400000];
long long sum[100001];

int init(int node, int start, int end)
{
    if (start > N)
        return -1;
    if (start == end)
        return seg[node] = start;

    int middle = (start + end) / 2;

    int lefti = init(node * 2, start, middle);
    int righti = init(node * 2 + 1, middle + 1, end);
    if (lefti == -1)
        seg[node] = righti;
    else if (righti == -1)
        seg[node] = lefti;
    else if (A[lefti] < A[righti])
        seg[node] = lefti;
    else
        seg[node] = righti;
    return seg[node];
}

int get_min_index(int node, int left, int right, int start, int end)
{

    if (left > end || right < start)
        return -1;

    if (left <= start && right >= end)
        return seg[node];

    int middle = (start + end) / 2;

    int lefti = get_min_index(node * 2, left, right, start, middle);
    int righti = get_min_index(node * 2 + 1, left, right, middle + 1, end);

    if (lefti == -1)
        return righti;
    if (righti == -1)
        return lefti;
    if (A[lefti] < A[righti])
        return lefti;
    return righti;
}

long long solve(int left, int right)
{
    int index = get_min_index(1, left, right, 1, pow(2, ceil(log2(N))));
    long long ans = sum[right] - sum[left - 1];
    ans = ans * A[index];

    if (index - 1 >= left)
    {
        ans = max(ans, solve(left, index - 1));
    }
    if (index + 1 <= right)
    {
        ans = max(ans, solve(index + 1, right));
    }

    //cout << left << " " << right << " " << ans << "\n";
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int i;
    for (i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    for (i = 1; i <= N; i++)
    {
        sum[i] = sum[i - 1] + A[i];
    }

    init(1, 1, pow(2, ceil(log2(N))));

    cout << solve(1, N) << "\n";

    return 0;
}
