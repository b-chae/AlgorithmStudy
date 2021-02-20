#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[200];
vector<int> lis;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int i;

    lis.push_back(-1);

    for (i = 0; i < N; i++)
    {
        cin >> A[i];

        if (lis.back() <= A[i])
        {
            lis.push_back(A[i]);
        }
        else
        {
            vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), A[i]);
            *it = A[i];
        }
    }

    cout << N - (lis.size() - 1) << "\n";
    return 0;
}
