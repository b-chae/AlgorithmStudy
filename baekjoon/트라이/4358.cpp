#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> trees;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int total = 0;

    while (getline(cin, str))
    {
        if (trees.count(str) == 0)
        {
            trees[str] = 1;
        }
        else
        {
            trees[str]++;
        }
        total++;
    }

    vector<pair<string, int> > toVector(trees.begin(), trees.end());

    sort(toVector.begin(), toVector.end());
    for (pair<string, int> v : toVector)
    {
        printf("%s %.4f\n", v.first.c_str(), (float)v.second * 100 / total);
    }

    return 0;
}
