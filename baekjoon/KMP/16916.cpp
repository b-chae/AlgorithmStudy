#include <iostream>
#include <vector>

using namespace std;

int main()
{

    string s, p;
    cin >> s >> p;

    vector<int> pi(p.length(), 0);
    int j = 0;
    for (int i = 1; i < p.length(); i++)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }

        if (p[i] == p[j])
        {
            pi[i] = ++j;
        }
    }

    j = 0;
    for (int i = 0; i < s.length(); i++)
    {

        while (j > 0 && s[i] != p[j])
        {
            j = pi[j - 1];
        }

        if (s[i] == p[j])
        {
            j++;
        }

        if (j == p.length())
        {
            cout << "1\n";
            return 0;
        }
    }

    cout << "0\n";

    return 0;
}
