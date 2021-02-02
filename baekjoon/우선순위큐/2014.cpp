#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
priority_queue<ll> pq;
map<ll, bool> visited;
int K, N;
ll prime[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;

    int i, j;
    for (i = 0; i < K; i++)
    {
        cin >> prime[i];
    }

    pq.push(-1);

    ll maxValue = 1;

    while (N > 0)
    {
        ll cur = -pq.top();
        pq.pop();

        for (i = 0; i < K; i++)
        {
            ll element = cur * prime[i];

            if (pq.size() > N && maxValue < element)
                continue;

            if (!visited.count(element))
            {
                maxValue = max(element, maxValue);
                pq.push(-element);
                visited[element] = true;
            }
        }
        N--;
    }

    cout << -pq.top() << "\n";

    return 0;
}
