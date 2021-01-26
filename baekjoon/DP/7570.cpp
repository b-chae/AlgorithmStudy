#include <iostream>
#include <algorithm>

using namespace std;

int N;
int D[1000001];
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int i, x;
    for (i = 1; i <= N; i++)
    {
        cin >> x;
        D[x] = D[x - 1] + 1;
        ans = max(ans, D[x]);
    }
    cout << N - ans << "\n";

    return 0;
}
