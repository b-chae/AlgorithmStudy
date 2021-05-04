#include <iostream>

using namespace std;

int A[10000][6];
int N;

int getbiggest(int n, int i){
    if(i==0 || i==5) return max(max(A[n][1], A[n][2]), max(A[n][3], A[n][4]));
    if(i==2 || i==4) return max(max(A[n][0], A[n][1]), max(A[n][3], A[n][5]));
    return max(max(A[n][0], A[n][2]), max(A[n][4], A[n][5]));
}

int oposite[6] = {5, 3, 4, 1, 2, 0};

int solve(int n, int top){

    if(n==N) return 0;

    int down;

    for(int i=0; i<6; i++){
        if(A[n-1][top] == A[n][i]){
            down = i;
            break;
        }
    }

    return solve(n+1, oposite[down]) + getbiggest(n, oposite[down]);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<6; j++){
            cin >> A[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<6; i++){
        ans = max(ans, solve(1, i) + getbiggest(0, i));
    }

    cout << ans << "\n";

    return 0;
}
