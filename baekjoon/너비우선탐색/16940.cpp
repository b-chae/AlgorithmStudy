#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
bool visited[100001];
vector<int> nextv[100001];
queue< pair<int, int> > q;
int check_ans[100001];
int p[100001];
int order[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N-1; i++){
        int x, y;
        cin >> x >> y;
        nextv[x].push_back(y);
        nextv[y].push_back(x);
    }

    for(int i=0; i<N; i++){
        cin >> check_ans[i];
    }

    q.push(make_pair(1, 1));
    visited[1] = true;

    while(!q.empty()){
        int x = q.front().first;
        int l = q.front().second;
        q.pop();

        for(int next:nextv[x]){
            if(!visited[next]){
                q.push(make_pair(next, l+1));
                visited[next] = true;
                p[next] = x;
            }
        }
    }

    for(int i=0; i<=N; i++){
        visited[i] = false;
    }

    visited[0] = true;
    int porder = -1;
    for(int i=0; i<N; i++){
        if(!visited[p[check_ans[i]]] || porder > order[p[check_ans[i]]]){
            cout << "0\n";
            return 0;
        }

        porder = order[p[check_ans[i]]];
        visited[check_ans[i]] = true;
        order[check_ans[i]] = i;
    }

    cout << "1\n";

    return 0;
}