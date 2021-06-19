#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, bool> graph[100001];
bool visited[100001];
int N;
queue<int> check;
bool flag = true;

void dfs(int n){

    //cout << n << "/";

    check.pop();
    visited[n]=true;

    while(!check.empty()){
        if(graph[n].find(check.front())!=graph[n].end() && !visited[check.front()]){
            dfs(check.front());
        }
        else{
            return;
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int x, y;

    for(int i=0; i<N-1; i++){
        cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }

    for(int i=0; i<N; i++){
        cin >> x;
        check.push(x);
    }

    if(check.front()==1)
    dfs(check.front());

    if(check.empty()) cout << "1\n";
    else cout << "0\n";


    return 0;
}