#include <iostream>

using namespace std;

string A,B,C;
int DP[101][101][101];
int ans = 0;

int solve(int a, int b, int c){
    if(a>=A.length() || b>=B.length() || c>=C.length()) return 0;
    if(DP[a][b][c] != -1) return DP[a][b][c];

    int result = 0;
    result = max(max(solve(a+1, b, c), solve(a, b+1, c)), solve(a,b,c+1));
    result = max(result, max(max(solve(a+1, b+1, c), solve(a+1, b, c+1)), solve(a, b+1, c+1)));
    bool check = (A[a] == B[b] && B[b] == C[c]);
    result = max(result, check + solve(a+1, b+1, c+1));
    return DP[a][b][c] = result;
}

int main(){
    cin >> A >> B >> C;

    for(int i=0; i<A.length(); i++){
        for(int j=0; j<B.length(); j++){
            for(int k=0; k<C.length(); k++){
                DP[i][j][k] = -1;
            }
        }
    }
    cout << solve(0, 0, 0) << "\n";
    return 0;
}