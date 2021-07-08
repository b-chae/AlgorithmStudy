#include <iostream>

using namespace std;

int N, M;
int C[30];
int T[7];
int D[30][15001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> C[i];
        D[i][0] = 1;
    }

    D[0][C[0]]=1;

    for(int i=1; i<N; i++){
        for(int j=0; j<=15000; j++){
            D[i][j] = max(D[i][j], D[i-1][j]);
            if(j-C[i] >= 0) D[i][j] = max(D[i][j], D[i-1][j-C[i]]);
        }
    }

    cin >> M;
    for(int i=0; i<M; i++){
        bool flag = false;
        cin >> T[i];
        for(int j=0; j+T[i] <= 15000; j++){
            if(D[N-1][j] == 1 && D[N-1][j+T[i]] == 1){
                flag = true;
                break;
            }
        }
        if(flag) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}