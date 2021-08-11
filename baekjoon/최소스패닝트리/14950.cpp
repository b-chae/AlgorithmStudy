#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, T;
priority_queue< pair<int, pair<int, int> > > pq;
int p[10001];

int getp(int n){
    if(p[n] == n) return n;
    return p[n] = getp(p[n]);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;

    for(int i=1; i<=N; i++){
        p[i] = i;
    }

    for(int i=0; i<M; i++){
        int x, y, z;
        cin >> x >> y >> z;
        pq.push(make_pair(-z, make_pair(x,y)));
    }

    int selected = 0;
    int offset = 0;
    long long ans = 0;
    while(!pq.empty() && selected < N-1){
        int c = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(getp(x) != getp(y)){
            p[p[x]] = p[y];
            ans += c + offset;
            offset += T;
            selected++;
        }
    }

    cout << ans << "\n";

    return 0;
}