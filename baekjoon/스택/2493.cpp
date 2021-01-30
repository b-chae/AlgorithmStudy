#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > stack;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int i, x;
    for (i = 0; i < N; i++)
    {
        cin >> x;
        if (stack.empty())
        {
            cout << "0 ";
            stack.push_back({i + 1, x});
        }
        else if (stack.back().second < x)
        {
            while (!stack.empty() && stack.back().second < x)
            {
                stack.pop_back();
            }
            if (stack.empty())
            {
                cout << "0 ";
            }
            else
            {
                cout << stack.back().first << " ";
            }
            stack.push_back({i + 1, x});
        }
        else
        {
            cout << stack.back().first << " ";
            stack.push_back({i + 1, x});
        }
    }
    return 0;
}
