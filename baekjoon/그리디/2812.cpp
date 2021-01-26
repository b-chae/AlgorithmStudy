#include <iostream>
#include <vector>

using namespace std;

int N, K;
string s;
vector<int> stack;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> s;
    int i;
    for (i = 0; i < N; i++)
    {
        if (stack.empty() || stack.back() >= s[i] - '0')
        {
            stack.push_back(s[i] - '0');
        }
        else if (K > 0)
        {
            stack.pop_back();
            K--;
            i--;
        }
        else
        {
            stack.push_back(s[i] - '0');
        }
    }
    while (K > 0)
    {
        stack.pop_back();
        K--;
    }
    for (int s : stack)
    {
        cout << s;
    }
    cout << "\n";
    return 0;
}
