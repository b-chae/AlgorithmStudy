#include <iostream>
#include <vector>

using namespace std;

int N, A, B;
vector< pair<int, int> > edges[100001];
bool visited[100001];
bool flag = false;
long long total = 0;
long long maxCost = 0;

bool dfs(int n){

    visited[n] = true;
    if(n==B) return true;

    for(pair<int, int> edge: edges[n]){
        int next = edge.second;
        int cost = edge.first;
        if(!visited[next]){
            if(dfs(next)){
                total += cost;
                if(maxCost < cost) maxCost = cost;
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A >> B;

    for(int i=0; i<N-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back(make_pair(z, y));
        edges[y].push_back(make_pair(z, x));
    }

    dfs(A);

    cout << total - maxCost << "\n";

    return 0;
}