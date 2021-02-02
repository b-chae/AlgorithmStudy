#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > stack;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stack.push_back({-1, 0});
        }
        else if (s[i] == ')')
        {

            int tmp = 0;
            while (stack.back().first != -1)
            {
                tmp += stack.back().first;
                stack.pop_back();
            }
            stack.pop_back();
            tmp *= stack.back().second;
            stack.pop_back();
            stack.push_back({tmp, tmp});
        }
        else
        {
            stack.push_back({1, s[i] - '0'});
        }
    }

    int ans = 0;
    while (!stack.empty())
    {
        ans += stack.back().first;
        stack.pop_back();
    }
    cout << ans << "\n";
    return 0;
}
