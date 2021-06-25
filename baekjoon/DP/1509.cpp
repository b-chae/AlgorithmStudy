#include <iostream>

using namespace std;
int DP[2500][2500];
int DP2[2501];

int main(){
    string str;
    cin >> str;

    for(int i=0; i<str.length(); i++) DP[i][i] = 1;
    for(int i=0; i<str.length()-1; i++)
        if(str[i]==str[i+1]) DP[i][i+1] = 2;

    for(int j=1; j<str.length(); j++){
        for(int i=j-1; i>=0; i--){
            if(str[i] == str[j] && DP[i+1][j-1] > 0) DP[i][j] = DP[i+1][j-1]+2;
        }
    }

    // for(int i=0; i<str.length(); i++){
    //     for(int j=0; j<str.length(); j++){
    //         cout << DP[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    for(int i=1; i<=str.length(); i++) DP2[i] = 25000;

    for(int j=0; j<str.length(); j++){
        for(int i=0; i<str.length(); i++){
            if(DP[i][j]>0) DP2[j+1] = min(DP2[j+1], DP2[i] + 1);
        }
    }

    cout << DP2[str.length()] << "\n";

    return 0;
}