#include <iostream>
#include <vector>

using namespace std;

int N;
int A[1000000];
int ans[1000000];
vector<int> stack;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int i;
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (i = N - 1; i >= 0; i--)
    {
        while (!stack.empty() && stack.back() <= A[i])
        {
            stack.pop_back();
        }

        if (stack.empty())
        {
            ans[i] = -1;
            stack.push_back(A[i]);
        }
        else
        {
            ans[i] = stack.back();
            stack.push_back(A[i]);
        }
    }

    for (i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
