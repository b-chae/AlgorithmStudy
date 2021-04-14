#include <iostream>

using namespace std;

int A[100][2];
long long D[100][10001];

int main()
{
    int T, N;
    cin >> T >> N;

    for(int i=0;i<N;i++){
        cin >> A[i][0] >> A[i][1];
    }

    for(int k=0; k<=A[0][1]; k++){
        if(A[0][0]*k > T) break;
        D[0][A[0][0]*k] = 1;
    }

    for(int i=1;i<N;i++){
        for(long long j=0;j<=T;j++){
            if(D[i-1][j] == 0) continue;
            for(int k=0; k<=A[i][1]; k++){
                if(j+A[i][0]*k > T) break;
                D[i][j+A[i][0]*k] += D[i-1][j];
            }
        }
    }

    cout << D[N-1][T] << "\n";

    return 0;
}
