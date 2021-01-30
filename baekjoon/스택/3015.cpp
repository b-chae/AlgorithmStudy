#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
vector<ll> stack;
int N;

int getlb(int left, int right, ll key)
{
    if (left >= right)
        return left;

    int middle = (left + right) / 2 + 1;
    if (stack[middle] <= key)
    {
        return getlb(left, middle - 1, key);
    }
    else
    {
        return getlb(middle, right, key);
    }
}

int getSize(ll x)
{
    int index = getlb(0, stack.size() - 1, x);
    return stack.size() - index;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int i;
    ll x, ans = 0;

    for (i = 0; i < N; i++)
    {
        cin >> x;
        if (stack.empty())
        {
            stack.push_back(x);
        }
        else if (stack.back() > x)
        {
            ans += 1;
            stack.push_back(x);
        }
        else
        {
            ans += getSize(x);
            while (!stack.empty() && stack.back() < x)
            {
                stack.pop_back();
            }
            stack.push_back(x);
        }
    }

    cout << ans << "\n";
    return 0;
}
