#include <iostream>

using namespace std;

#define OFFSET 200000
bool exist[400010];
int A[5000];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int x;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];

        for (int j = 0; j < i; j++)
        {
            if (exist[A[i] - A[j] + OFFSET])
            {
                ans++;
                break;
            }
        }

        for (int j = 0; j <= i; j++)
        {
            exist[A[j] + A[i] + OFFSET] = true;
        }
    }

    cout << ans << "\n";
    return 0;
}
