#include <iostream>

using namespace std;

int T, L;
long long D[5001];

int solve(int n){
    if(D[n]!=0 || n%2==1) return D[n];

    for(int y = 2; y<= n; y+= 2){
        D[n] = (D[n] + (long long)solve(y-2)*solve(n-y)) % 1000000007;
    }
    return D[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    int i, j;

    D[0]=1;
    D[2]=1;

    for (i = 0; i < T; i++)
    {
        cin >> L;
        cout << solve(L) << "\n";
    }
    return 0;
}
