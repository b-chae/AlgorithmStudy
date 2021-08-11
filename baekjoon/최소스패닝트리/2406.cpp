#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int p[1001];
priority_queue< pair<int, pair<int, int> > > pq;
int cost[1001][1001];
vector< pair<int, int> > ans;

int getp(int n){
    if(n == p[n]) return n;
    return p[n] = getp(p[n]);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for(int i=1; i<=N; i++) p[i] = i;
    
    int selected = 0;

    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        if(getp(x) != getp(y)){
            selected++;
            p[p[x]] = p[y];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> cost[i][j];
            if(i!=1 && i<j) pq.push(make_pair(-cost[i][j], make_pair(i, j)));
        }
    }

    long long total = 0;
    int connected = 0;
    while(!pq.empty() && selected < N-2){
        int c = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(getp(x)!=getp(y)){
            selected++;
            p[p[x]] = p[y];
            total += c;
            connected++;
            ans.push_back(make_pair(x, y));
        }
    }

    cout << total << " " << connected << "\n";
    for(pair<int, int> a:ans){
        cout << a.first << " " << a.second << "\n";
    }

    return 0;
}