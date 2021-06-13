#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<string, bool> visited;
queue< pair<string, int> > q;
int dx[9][4] = {
    {1, 3, -1, -1},
    {0, 2, 4, -1},
    {1, 5, -1, -1},
    {0, 4, 6, -1},
    {3, 5, 1, 7},
    {4, 2, 8, -1},
    {3, 7, -1, -1},
    {6, 4, 8, -1},
    {7, 5, -1, -1}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string start = "";

    int x;

    for(int i=0; i<9; i++){
        cin >> x;
        start += x+'0';
    }

    visited[start] = true;
    q.push(make_pair(start, 0));

    while(!q.empty()){
        string now = q.front().first;
        int n = q.front().second;
        q.pop();

        if(now == "123456780"){
            cout << n << "\n";
            return 0;
        }

        int find;
        for(int i=0; i<9; i++){
            if(now[i]=='0'){
                find=i;
                break;
            }
        }

        for(int i=0; i<4; i++){
            if(dx[find][i]==-1) break;
            string next;
            if(find<dx[find][i]){
                next = now.substr(0, find) + now[dx[find][i]] + now.substr(find+1, dx[find][i]-find-1) + "0" + now.substr(dx[find][i]+1, 8-dx[find][i]);
            }
            else{
                next = now.substr(0, dx[find][i]) + "0" + now.substr(dx[find][i]+1, find-dx[find][i]-1) + now[dx[find][i]] + now.substr(find+1, 8-find);
            }

            if(visited.find(next) == visited.end()){
                q.push(make_pair(next, n+1));
                visited[next] = true;
            }
        }
    }

    cout << "-1\n";

    return 0;
}