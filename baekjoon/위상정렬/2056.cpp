#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> v[10001];
priority_queue< pair <int, int> > q;
int t[10001];
int d[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> t[i];
        int x, y;
        cin >> x;
        for(int j=0; j<x; j++){
            cin >> y;
            v[y].push_back(i);
            d[i]++;
        }
    }

    for(int i=1; i<=N; i++){
        if(d[i] == 0){
            q.push(make_pair(-t[i], i));
        }
    }

    int ans = 0;

    while(!q.empty()){
        int x = q.top().second;
        int y = -q.top().first;
        q.pop();
        ans = max(ans, y);

        for(int k:v[x]){
            d[k]--;
            if(d[k]==0){
                q.push(make_pair(-y-t[k], k));
            }
        }
    }

    cout << ans << "\n";


    return 0;
}