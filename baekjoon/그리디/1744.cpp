#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> B;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, x;
    long long ans = 0;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> x;
        if (x > 0)
            A.push_back(x);
        else if (x <= 0)
            B.push_back(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (i = A.size() - 1; i >= 0; i--)
    {
        if (i > 0 && ((long long)A[i] * A[i - 1]) > ((long long)A[i] + A[i - 1]))
        {
            ans += (long long)A[i] * A[i - 1];
            i--;
        }
        else
        {
            ans += A[i];
        }
    }
    for (i = 0; i < B.size(); i++)
    {
        if (i + 1 < B.size())
        {
            ans += (long long)B[i] * B[i + 1];
            i++;
        }
        else
        {
            ans += B[i];
        }
    }

    cout << ans << "\n";

    return 0;
}
