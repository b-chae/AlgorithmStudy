#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int p1[1001];
int p2[1001];
int selected1 = 0, selected2 = 0, N, M;
long long total1 = 0, total2 = 0;
pair<int, pair<int, int> > edges[1000001];

int getp1(int n){
    if(p1[n] == n) return n;
    return p1[n] = getp1(p1[n]);
}

int getp2(int n){
    if(p2[n] == n) return n;
    return p2[n] = getp2(p2[n]);
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<=N; i++) {
        p1[i] = i;
        p2[i] = i;
    }

    for(int i=0; i<M+1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = make_pair(z, make_pair(x,y));
    }

    sort(edges, edges + M + 1);

    for(int now=M; selected1 < N; now--){

        int d = edges[now].first;
        int x = edges[now].second.first;
        int y = edges[now].second.second;

        if(getp1(x) != getp1(y)){
            p1[p1[x]] = p1[y];
            if(d==0) total1++;
            selected1++;
        }
    }

    for(int now=0; selected2 < N; now++){

        int d = edges[now].first;
        int x = edges[now].second.first;
        int y = edges[now].second.second;

        if(getp2(x) != getp2(y)){
            p2[p2[x]] = p2[y];
            if(d==0) total2++;
            selected2++;
        }
    }

    cout << -total1*total1 + total2*total2 << "\n";

    return 0;
}
