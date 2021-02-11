#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int due;
    int score;

    bool operator<(const node &a) const
    {
        if (a.due == due)
            return score < a.score;
        return due > a.due;
    }
};

int N;
priority_queue<node> pq;
priority_queue<int> doit;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int x, y;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        pq.push({x, y});
    }

    int time = 1;
    int ans = 0;
    while (!pq.empty())
    {
        int d = pq.top().due;
        int s = pq.top().score;
        pq.pop();

        //cout << d << " " << s << " " << ans << "\n";

        if (d >= time)
        {
            ans += s;
            doit.push(-s);
            time++;
        }
        else if (!doit.empty() && -doit.top() < s)
        {
            ans += doit.top();
            doit.pop();
            doit.push(-s);
            ans += s;
        }
    }

    cout << ans << "\n";
    return 0;
}
