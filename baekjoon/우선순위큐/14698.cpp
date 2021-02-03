#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int T, N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int i, j;
    for (i = 0; i < T; i++)
    {
        ll x, ans = 1;
        cin >> N;
        priority_queue<ll> pq;
        for (j = 0; j < N; j++)
        {
            cin >> x;
            pq.push(-x);
        }
        while (pq.size() > 1)
        {
            ll tmp = pq.top();
            pq.pop();
            tmp *= pq.top();
            pq.pop();
            //cout << tmp << " ";
            pq.push(-tmp);
            ans = (ans * (tmp % 1000000007)) % 1000000007;
        }
        cout << ans << "\n";
    }
    return 0;
}
