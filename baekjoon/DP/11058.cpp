#include <iostream>

using namespace std;

long long D[105];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    D[1]=1;D[2]=2;D[3]=3;

    for(int i=3; i<=N; i++){
        D[i] = D[i-1]+1;
        for(int j=1; j<=i-3-1; j++){
            D[i] = max(D[i], D[i-3-j]*(2+j));
        }
    }

    cout << D[N]<<"\n";

    return 0;
}
