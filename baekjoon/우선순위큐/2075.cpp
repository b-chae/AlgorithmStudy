#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int i, j, x;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> x;
            if (pq.size() < N)
                pq.push(-x);
            else if (-pq.top() < x)
            {
                pq.pop();
                pq.push(-x);
            }
        }
    }

    cout << -pq.top() << "\n";

    return 0;
}
