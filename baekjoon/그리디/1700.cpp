#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> elec;
int use[101];
int uselength = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int i, j, x, u;
    int ans = 0;
    for (i = 0; i < K; i++)
    {
        cin >> x;
        elec.push_back(x);
    }

    for (i = 0; i < K; i++)
    {
        int now = elec[i];

        bool flag = false;
        for (u = 0; u < uselength; u++)
        {
            if (use[u] == now)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        if (uselength < N)
        {
            use[uselength] = now;
            uselength++;
            continue;
        }

        int next = 0;
        int lastIndex = -1;

        for (u = 0; u < uselength; u++)
        {
            flag = false;
            for (j = i + 1; j < K; j++)
            {
                if (use[u] == elec[j])
                {
                    flag = true;
                    if (lastIndex < j)
                    {
                        lastIndex = j;
                        next = u;
                    }
                    break;
                }
            }
            if (!flag)
            {
                next = u;
                break;
            }
        }

        use[next] = now;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}
