#include <iostream>

using namespace std;

int N, D, K, C;
int include[3001];
int A[3000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, x;
    int count = 0;
    int ans = 0;
    int kind = 0;

    cin >> N >> D >> K >> C;
    include[C]++;
    kind = 1;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int left = 0, right = 0;
    if (include[A[0]] == 0)
    {
        kind++;
    }
    include[A[0]]++;
    count = 1;
    ans = kind;

    while (left < N)
    {
        if (count <= K)
        {
            right++;
            count++;
            if (right == N)
                right = 0;

            if (include[A[right]] == 0)
            {
                kind++;
            }
            include[A[right]]++;
        }
        else
        {
            include[A[left]]--;
            if (include[A[left]] == 0)
            {
                kind--;
            }

            left++;
            count--;
        }

        if (count == K)
            ans = max(ans, kind);
    }

    cout << ans << "\n";
    return 0;
}
