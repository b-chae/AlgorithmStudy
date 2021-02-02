#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;

char target[4] = {'P', 'P', 'A', 'P'};

void print()
{
    for (int s : stack)
    {
        cout << s << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == 'P')
        {
            if (!stack.empty() && stack.back() == 1)
            {
                stack.push_back(2);
            }
            else
                stack.push_back(0);
        }
        else
        {
            stack.push_back(1);
        }

        while (stack.back() == 2)
        {
            stack.pop_back();
            stack.pop_back();
            if (!stack.empty() && stack.back() != 1)
            {
                stack.pop_back();
                if (!stack.empty() && stack.back() != 1)
                {
                    stack.pop_back();
                }
                else
                {
                    cout << "NP\n";
                    return 0;
                }
            }
            else
            {
                cout << "NP\n";
                return 0;
            }

            if (!stack.empty() && stack.back() == 1)
                stack.push_back(2);
            else
                stack.push_back(0);
        }
    }

    if (!stack.empty() && (stack.back() == 1 || stack.size() > 1))
    {
        cout << "NP\n";
    }
    else
        cout << "PPAP\n";

    return 0;
}
