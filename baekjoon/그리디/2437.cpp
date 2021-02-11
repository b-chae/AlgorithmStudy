#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int i;
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A, A + N);

    int sum = 0;
    for (i = 0; i < N; i++)
    {
        if (sum + 1 < A[i])
        {
            cout << sum + 1 << "\n";
            return 0;
        }
        sum += A[i];
    }

    cout << sum + 1 << "\n";

    return 0;
}
