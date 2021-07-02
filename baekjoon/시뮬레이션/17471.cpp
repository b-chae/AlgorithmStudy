#include <iostream>
#include <vector>

using namespace std;

int N;
int P[11];
vector<int> edges[11];
int ans = 10000;
bool visited[11];
int check[12];

void dfs(int n, int k){
    visited[n] = true;
    for(int next:edges[n]){
        if(!visited[next] && check[next]==k){
            dfs(next, k);
        }
    }
}

void solve(int n){
    if(n==N+1){
        for(int i=1; i<=N; i++) visited[i] = false;
        for(int i=1; i<=N; i++){
            if(check[i] == 0){
                dfs(i, 0);
                break;
            }
        }
        for(int i=1; i<=N; i++){
            if(check[i] == 11){
                dfs(i, 11);
                break;
            }
        }
        for(int i=1; i<=N; i++){
            if(!visited[i]) return;
        }

        int p1=0, p2=0;
        for(int i=1; i<=N; i++){
            if(check[i] == 0) p1+=P[i];
            else p2 += P[i];
        }
        if(p1==0 || p2==0) return;
        ans = min(ans, abs(p1-p2));
        return;
    }

    check[n] = 0;
    solve(n+1);
    check[n] = 11;
    solve(n+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> P[i];
    }

    int x, tmp;
    for(int i=1; i<=N; i++){
        cin >> x;
        for(int j=0; j<x; j++){
            cin >> tmp;
            edges[i].push_back(tmp);
        }
    }

    solve(1);

    if(ans == 10000) cout << "-1\n";
    else cout << ans << "\n";

    return 0;
}