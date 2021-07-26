#include <iostream>

using namespace std;

int N;
int A[50000];
int D[50001][4];
int S[50001];
int T;

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    cin >> T;

    S[1] = A[0];
    for(int i=2; i<=N; i++) S[i] = S[i-1]+A[i-1];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=3; j++){
            D[i][j] = D[i-1][j];
            if(i-T>=0) D[i][j] = max(D[i][j], D[i-T][j-1] + S[i]-S[i-T]);
            cout << D[i][j] << " ";
        }
        cout << "\n";
    }

    cout << D[N][3] << "\n";

    return 0;
}