#include <iostream>

using namespace std;

int T, N;
int won[20];
int M;
long long DP[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> won[i];
        }
        cin >> M;

        for(int j=0; j<=M; j++) DP[j] = 0;
        DP[0] = 1;

        for(int i=0; i<N; i++){
            for(int j=won[i]; j<=M; j++){
                DP[j] += DP[j-won[i]];
            }
        }

        cout << DP[M] << "\n";
    }

    return 0;
}