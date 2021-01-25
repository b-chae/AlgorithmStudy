#include <iostream>
#include <queue>

using namespace std;
int N;

struct Work
{
    long long deadline, ramen;

    bool operator<(const Work &a) const
    {
        if (ramen == a.ramen)
        {
            return deadline > a.deadline;
        }
        return ramen > a.ramen;
    }
};

struct PushedWork
{
    long long deadline, ramen;

    bool operator<(const PushedWork &a) const
    {
        if (deadline == a.deadline)
        {
            return ramen < a.ramen;
        }
        return deadline > a.deadline;
    }
};

priority_queue<PushedWork> pq;
priority_queue<Work> pq2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int i;
    long long x, y;
    long long ans = 0;
    for (i = 0; i < N; i++)
    {
        cin >> x >> y;
        pq.push({x, y});
    }

    int workdeadline = 1;
    for (i = 1; i <= N; i++)
    {
        long long deadline = pq.top().deadline;
        long long ramen = pq.top().ramen;
        pq.pop();

        //cout << i << " " << deadline << " " << ramen << "\n";

        if (deadline >= workdeadline)
        {
            pq2.push({deadline, ramen});
            ans += ramen;
            workdeadline++;
        }
        else if (!pq2.empty() && pq2.top().ramen < ramen)
        {
            pq2.push({deadline, ramen});
            ans += ramen - pq2.top().ramen;
            pq2.pop();
        }
        //cout << ans << "\n";
    }

    cout << ans << "\n";
    return 0;
}
