#include <iostream>
#include <vector>

using namespace std;
vector<pair<char, int> > stack;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string target;

    cin >> s >> target;

    int i;
    for (i = 0; i < s.length(); i++)
    {
        if (stack.empty())
        {
            int tmp = target[0] == s[i] ? 0 : -1;
            stack.push_back({s[i], tmp});
        }
        else
        {
            int checkIndex = stack.back().second + 1;
            int tmp;
            if (target[checkIndex] == s[i])
                tmp = checkIndex;
            else if (target[0] == s[i])
                tmp = 0;
            else
                tmp = -1;

            stack.push_back({s[i], tmp});
        }

        if (stack.back().second == target.length() - 1)
        {
            int count = 0;
            while (count < target.length())
            {
                stack.pop_back();
                count++;
            }
        }
    }

    if(stack.empty()){
        cout << "FRULA\n";
    }
    else{
        for(pair<char, int> a : stack){
            cout << a.first;
        }
        cout <<"\n";
    }
    return 0;
}
