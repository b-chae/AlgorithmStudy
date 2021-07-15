#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
priority_queue< pair <int,int> > pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        pq.push({-x, -y});
    }

    int ans = 0;

    int left = -1000000000;
    int right = -1000000000;

    while(!pq.empty()){
        int x = -pq.top().first;
        int y = -pq.top().second;
        pq.pop();

        if(y<=right) continue;
        if(x<=right){
            right = y;
        }
        else{
            ans += right-left;
            left = x;
            right = y;
        }
    }
    ans += right-left;

    cout << ans << "\n";

    return 0;
}