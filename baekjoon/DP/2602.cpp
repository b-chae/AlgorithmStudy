#include <iostream>

using namespace std;

string target;
string dari[2];
int DP[2][101][21];

long long solve(int row, int col, int idx){

    //cout << row << col << idx <<"\n";

    if(idx == target.length()-1){
        return 1;
    }

    if(DP[row][col][idx] != -1) return DP[row][col][idx];

    int nrow = 1 - row;

    long long res = 0;
    for(int j=col+1; j<dari[0].length(); j++){
        if(dari[nrow][j] == target[idx+1]){
            res += solve(nrow, j, idx+1);
        }
    }

    return DP[row][col][idx] = res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> target >> dari[0] >> dari[1];

    for(int i=0;i<2;i++){
        for(int j=0;j<dari[0].length();j++){
            for(int k=0;k<target.length();k++){
                DP[i][j][k]=-1;
            }
        }
    }

    long long result = 0;
    for(int i=0; i<2; i++){
        for(int j=0;j<dari[0].length();j++){
            if(dari[i][j] == target[0])
                result += solve(i, j, 0);
        }
    }

    cout << result << "\n";

    return 0;
}
