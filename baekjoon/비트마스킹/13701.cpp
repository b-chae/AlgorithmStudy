#include <iostream>

using namespace std;
int a[1 << 20], x;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> x)
    {
        int q = x / 32;
        int r = x % 32;

        if ((a[q] & (1 << r)) != (1 << r))
        {
            cout << x << " ";
            a[q] |= (1 << r);
        }
    }
    return 0;
}
