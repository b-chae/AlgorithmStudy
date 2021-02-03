#include <iostream>
#include <queue>

using namespace std;

struct out
{
    int n, number, time;

    bool operator<(const out &a) const
    {
        if (time == a.time)
            return n < a.n;
        return time > a.time;
    }
};

struct in
{
    int n, number, time;

    bool operator<(const in &a) const
    {
        if (time == a.time)
            return n > a.n;
        return time > a.time;
    }
};

priority_queue<out> O;
priority_queue<in> I;
int N, K;
long long ans = 0;
int totaltime = 0;
int cus[100000][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    int i, j, x, y;
    for (i = 1; i <= K; i++)
    {
        I.push({i, 0, 0});
    }

    for (i = 0; i < N; i++)
    {
        cin >> cus[i][0] >> cus[i][1];
    }

    int current = 0;
    int out = 1;
    while (current < N)
    {
        if (I.top().time <= totaltime)
        {
            struct in t = I.top();
            I.pop();
            t.number = cus[current][0];
            t.time += cus[current][1];
            I.push(t);
            O.push({t.n, t.number, t.time});
            cout << "in " << t.n << " " << current << " " << totaltime << "\n";
            current++;
        }
        else
        {
            totaltime++;
        }
    }

    while (!O.empty())
    {
        ans += (long long)O.top().number * out;
        O.pop();
        out++;
    }

    cout << ans << "\n";

    return 0;
}
