#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000001

int N;
int D[1000][1000];
vector< pair<int, int> > edges[1000000];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
priority_queue< pair<int, int > > pq;
int dist[1000000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> D[i][j];
        }
    }

    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            for(int k = 0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                edges[x*N+y].push_back(make_pair(nx*N+ny, abs(D[x][y]-D[nx][ny])));
            }
        }
    }

    for(int i=0; i<=N*N-1; i++) dist[i] = INF;
    dist[0] = 0;
    pq.push(make_pair(0, 0));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(dist[x] < cost) continue;

        for(pair<int, int> next : edges[x]){
            if(dist[next.first] > max(next.second, cost)){
                dist[next.first] = max(next.second, cost);
                pq.push(make_pair(-dist[next.first], next.first));
            }
        }
    }

    cout << dist[N*N-1] << "\n";

    return 0;
}