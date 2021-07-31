#include <iostream>

using namespace std;

string str;
int DP[500][500];

int main(){
    cin >> str;

    for(int j=1; j<str.length(); j++){
        for(int i=j-1; i>=0; i--){
            DP[i][j] = max(DP[i+1][j], DP[i][j-1]);

            if(str[i] == 'a' && str[j] == 't'){
                DP[i][j] = max(DP[i][j], DP[i+1][j-1] + 2);
            }
            else if(str[i] == 'g' && str[j] == 'c'){
                DP[i][j] = max(DP[i][j], DP[i+1][j-1] + 2);
            }

            for(int k=i+1; k+1<j; k++){
                DP[i][j] = max(DP[i][j], DP[i][k] + DP[k+1][j]);
            }
            //cout << "[" << i << " " << j << "]" << DP[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << DP[0][str.length()-1] << "\n";
    return 0;
}