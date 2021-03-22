#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    string s, target;
    cin >> s >> target;

    while (s != target && target.length() > 0)
    {
        int index = target.length() - 1;
        if (target[index] == 'A')
        {
            target = target.substr(0, index);
        }
        else
        {
            target = target.substr(0, index);
            reverse(target.begin(), target.end());
        }
        cout << target << "\t";
    }

    if (s == target)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }

    return 0;
}
