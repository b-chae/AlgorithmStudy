#include <iostream>

using namespace std;

int G;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> G;

    int left = 1, right = 1;
    bool flag = false;

    while (right <= 100000)
    {
        long long now = (long long)right * right - (long long)left * left;
        if (now == G)
        {
            flag = true;
            cout << right << "\n";
            left++;
        }
        else if (now < G)
        {
            right++;
        }
        else
        {
            left++;
        }
    }

    if (!flag)
    {
        cout << "-1\n";
    }

    return 0;
}
