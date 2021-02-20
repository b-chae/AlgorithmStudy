#include <iostream>

using namespace std;

int N;

class Tree
{

public:
    bool isEnd = false;
    Tree *next[26];
    int nextcount = 0;
    int count = 0;

    ~Tree()
    {
        for (int i = 0; i < 26; i++)
            if (next[i] != NULL)
                delete next[i];
    }
};

class TrieTree
{

public:
    Tree *root = new Tree();

    void insert(string str)
    {
        Tree *current = root;

        for (int i = 0; i < str.length(); i++)
        {
            int index = str[i] - 'a';
            if (current->next[index] == NULL)
            {
                current->next[index] = new Tree();
                current->nextcount++;
            }
            current = current->next[index];
            current->count++;
        }

        current->isEnd = true;
    }

    int dfs(Tree *current)
    {
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (current->next[i] != NULL)
            {
                if (current->isEnd || current->nextcount != 1 || current == root)
                {
                    res += current->next[i]->count;
                }
                res += dfs(current->next[i]);
            }
        }
        return res;
    }

    int ans()
    {
        int res = dfs(root);
        return res;
    }

    ~TrieTree()
    {
        delete root;
    }
};
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N)
    {
        TrieTree trieTree;
        for (int i = 0; i < N; i++)
        {
            string str;
            cin >> str;
            trieTree.insert(str);
        }

        printf("%.2f\n", (double)trieTree.ans() / N);
    }

    return 0;
}
