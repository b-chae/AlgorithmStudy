#include <iostream>
#include <queue>

using namespace std;

struct node{
    int p, d;

    bool operator<(const struct node& a) const{
        if(p == a.p){
            return d<a.d;
        }
        return p<a.p;
    }
};

int N;
priority_queue< node > pq;
bool used[10001];
int parent[10001];

int getp(int n){
    if(parent[n] == n) return n;
    return parent[n] = getp(parent[n]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        pq.push({x,y});
    }
    for(int i=1; i<=10000; i++) parent[i] = i;

    int ans = 0;

    while(!pq.empty()){
        int d = pq.top().d;
        int p = pq.top().p;
        pq.pop();

        parent[d] = getp(d);
        if(parent[d]!=0){
            used[parent[d]] = true;
            ans+=p;
            //cout << p << " " << parent[d] << "\n";
            parent[parent[d]] = getp(parent[d]-1);
        }
    }

    cout << ans << "\n";

    return 0;
}