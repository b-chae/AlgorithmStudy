#include <iostream>
#include <string>

using namespace std;

bool notPrime[1003002];

void goprime()
{
    notPrime[1] = true;
    for (long long i = 2; i <= 500000; i++)
    {
        if (notPrime[i])
            continue;
        for (long long j = 2; i * j <= (long long)1003001; j++)
        {
            notPrime[i * j] = true;
        }
    }
}

bool pelindrum(string s, int n)
{
    if (n == 1 || n == 0)
        return true;

    if (s[0] == s[n - 1])
        return pelindrum(s.substr(1, n - 2), n - 2);
    else
        return false;
}

int main()
{
    goprime();

    int N;
    cin >> N;

    for (int i = N; i <= 1003001; i++)
    {
        if (notPrime[i])
            continue;

        string s = to_string(i);
        if (pelindrum(s, s.length()))
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
