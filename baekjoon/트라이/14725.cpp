#include <iostream>
#include <map>

using namespace std;

int N;

class Node{
    public:
    string str;
    map<string, Node*> children;

    Node(string s){
        str = s;
    }
};

Node* trie = new Node("root");

void dfs(Node* now, int level){
    if(now->children.empty()) return;
    map<string, Node*>::iterator it;
    for(it=now->children.begin(); it!=now->children.end(); it++){
        for(int i=0; i<level; i++) cout << "--";
        cout << it->first << "\n";
        dfs(it->second, level+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int x;
    string tmp;

    for(int i=0; i<N; i++){
        cin >> x;
        Node* now = trie;
        for(int j=0; j<x; j++){
            cin >> tmp;
            if(now->children.find(tmp)==now->children.end()){
                now->children[tmp] = new Node(tmp);
            }
            now = now->children[tmp];
        }
    }

    dfs(trie, 0);

    return 0;
}