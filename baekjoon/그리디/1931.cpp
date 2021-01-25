#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
long long endtime = 0, ans = 0;

struct Node
{
    long long start, end;

    inline bool operator<(const Node &a) const
    {
        if (end == a.end)
            return start < a.start;
        return end < a.end;
    }
};

vector<Node> meetings;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int i;
    long long x, y;
    for (i = 0; i < N; i++)
    {
        cin >> x >> y;
        meetings.push_back({x, y});
    }

    sort(meetings.begin(), meetings.end());

    for (i = 0; i < N; i++)
    {
        if (meetings[i].start >= endtime)
        {
            ans++;
            endtime = meetings[i].end;
        }
    }

    cout << ans << "\n";
    return 0;
}
