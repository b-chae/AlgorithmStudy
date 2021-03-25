#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> pi(s.length(), 0);

    int ans = 0;

    for (int index = 0; index < s.length() - 1; index++)
    {
        fill(pi.begin(), pi.end(), 0);
        int j = 0;
        for (int i = index + 1; i < s.length(); i++)
        {
            while (j > 0 && s[i] != s[j + index])
            {
                j = pi[j - 1 + index];
            }
            if (s[i] == s[j + index])
            {
                pi[i] = ++j;
            }
            ans = max(ans, pi[i]);
        }
    }

    cout << ans << "\n";

    return 0;
}
