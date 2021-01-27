#include <iostream>

using namespace std;

int N, M;
unsigned int alpha[10000];
unsigned int know = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    int i, j, x;
    unsigned char c;
    for (i = 'a' - 'a'; i <= 'z' - 'a'; i++)
    {
        know |= (1 << i);
    }

    for (i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (j = 0; j < s.length(); j++)
        {
            alpha[i] |= (1 << (s[j] - 'a'));
        }
    }

    for (i = 0; i < M; i++)
    {
        cin >> x >> c;
        if (x == 1 && (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'))
        {
            know &= ~(1 << (c - 'a'));
        }
        else if (x == 2)
        {
            know |= (1 << (c - 'a'));
        }

        int count = 0;
        for (j = 0; j < N; j++)
        {
            if ((know & alpha[j]) == alpha[j])
                count++;
        }
        cout << count << "\n";
    }

    return 0;
}
