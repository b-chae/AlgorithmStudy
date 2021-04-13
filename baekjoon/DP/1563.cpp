#include <iostream>

using namespace std;

int N;
bool visited[1001][5][5];
int D[1001][5][5];

// 출석 0 지각 1 결석 2

int solve(int n, int l, int a){
    if(visited[n][l][a]) return D[n][l][a];

    visited[n][l][a] = true;

    if(n == 1){
        if(l+a >= 2) return D[1][l][a] = 0;
        return D[1][l][a] = 1;
    }

    int res = 0;

    if(a>0){
        res += solve(n-1, l, a-1);
    }else{
        for(int i=0;i<=2; i++){
            res += solve(n-1, l, i);
        }
        if(l>0){
            for(int i=0;i<=2;i++){
                res += solve(n-1, l-1, i);
            }
        }
    }

    return D[n][l][a] = res % 1000000;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << (solve(N, 0, 0) + solve(N, 1, 0) + solve(N, 0, 1) + solve(N, 0, 2) + solve(N, 1, 1) + solve(N,1,2))%1000000<< "\n";

    return 0;
}
