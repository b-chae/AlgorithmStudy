#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct Jew
{
    long long m, v;

    bool operator<(const Jew &a) const
    {
        if (v == a.v)
            return m > a.m;
        return v < a.v;
    }
};

priority_queue<Jew> jews;
long long ans;
multiset<long long> back;
int N, K;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    long long x, y, i;
    for (i = 0; i < N; i++)
    {
        cin >> x >> y;
        jews.push({x, y});
    }
    for (i = 0; i < K; i++)
    {
        cin >> x;
        back.insert(x);
    }

    while (!jews.empty())
    {
        long long c = jews.top().v;
        long long w = jews.top().m;
        jews.pop();

        multiset<long long>::iterator it = back.lower_bound(w);
        //cout << *it << " ";
        if (it != back.end())
        {
            back.erase(it);
            ans += c;
        }
    }

    cout << ans << "\n";
    return 0;
}
