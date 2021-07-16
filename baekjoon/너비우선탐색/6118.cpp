#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool visited[20001];
vector<int> edges[20001];
queue< pair <int, int> > q;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    q.push(make_pair(1, 0));
    visited[1] = true;
    int length = 0;
    int ans = 1;
    int count = 0;

    while(!q.empty()){
        int n = q.front().first;
        int d = q.front().second;
        q.pop();

        if(length<d){
            ans = n;
            length = d;
            count = 1;
        }
        else if(length == d){
            count++;
            if(n<ans)ans = n;
        }

        for(int next:edges[n]){
            if(!visited[next]){
                q.push(make_pair(next, d+1));
                visited[next] = true;
            }
        }
    }

    cout << ans << " " << length << " " << count << "\n";

    return 0;
}