#include <iostream>

using namespace std;

int T, N;

class TrieNode
{
public:
    TrieNode *next[10];
    bool isEnd = false;
};

class Trie
{
public:
    TrieNode *root = new TrieNode();

    bool insert(string word)
    {
        TrieNode *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - '0';
            if (current->next[index] == NULL)
            {
                current->next[index] = new TrieNode();
            }
            else if (i == word.length() - 1)
            {
                current = current->next[index];
                current->isEnd = true;
                return false;
            }

            current = current->next[index];
            if (current->isEnd)
                return false;
        }
        current->isEnd = true;
        return true;
    }
};

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int i, j;
    string str;

    cin >> T;

    for (i = 0; i < T; i++)
    {

        Trie TrieTree;

        bool flag = true;
        cin >> N;
        for (j = 0; j < N; j++)
        {
            cin >> str;
            if (!TrieTree.insert(str))
            {
                flag = false;
            }
        }

        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
