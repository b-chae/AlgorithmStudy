#include <iostream>
#include <queue>

using namespace std;

struct node{
    int x, y;

    bool operator< (const node & a) const{
        if(y==a.y) return x > a.x;
        return y > a.y;
    }
};

int N, M;
priority_queue<node> pq;
priority_queue<int> include;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        if(x<=y){
            pq.push({x, y});
        }
        else{
            pq.push({y, x});
        }
    } 
    cin >> M;

    int start =  -1000000001;
    int end = -1000000001;
    int ans = 0;

    while(!pq.empty()){
        int x = pq.top().x;
        int y = pq.top().y;
        pq.pop();

        cout << "[" << x << " " << y << "]\n";

        if(y-x > M) continue;

        if(y<=end) include.push(-x);
        else{
            end = y;
            start = y-M;
            while(!include.empty()){
                int k = -include.top();
                if(k<start){
                    include.pop();
                }
                else{
                    break;
                }
            }
            include.push(-x);
        }

        ans = max(ans, (int)include.size());
    }

    cout << ans << "\n";


    return 0;
}