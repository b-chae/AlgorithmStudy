#include <iostream>

using namespace std;

int T, N, M;
long long D[15][2001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N >> M;
        for(int x=1; x<=M; x++) D[1][x] = 1;
        for(int x=2; x<=N; x++){
            for(int y=1; y<=M; y++){
                D[x][y] = 0;
                for(int k=1;k<=y/2;k++){
                    D[x][y] += D[x-1][k];
                }
            }
        }
        long long ans = 0;
        for(int y=1; y<=M; y++){
            ans += D[N][y];
        }
        cout << ans << "\n";
    }

    return 0;
}
