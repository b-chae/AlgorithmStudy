#include <iostream>

using namespace std;

class Tree
{
public:
    Tree *next[26] = {NULL, NULL, NULL, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL, NULL};
    int count = 0;
};

class TrieTree
{
public:
    Tree *root = new Tree();

    void insert(string str)
    {
        bool first = true;
        string ans = "";
        Tree *current = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (current->next[str[i] - 'a'] == NULL)
            {
                current->next[str[i] - 'a'] = new Tree();
                if (first)
                {
                    ans = str.substr(0, i + 1);
                    first = false;
                }
            }
            current = current->next[str[i] - 'a'];
        }

        current->count++;

        if (first)
        {
            if (current->count == 1)
            {
                cout << str << "\n";
            }
            else
            {
                cout << str << current->count << "\n";
            }
        }
        else
        {
            cout << ans << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string tmp;
    TrieTree trieTree;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        trieTree.insert(tmp);
    }

    return 0;
}
