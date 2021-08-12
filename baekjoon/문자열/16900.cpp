#include <iostream>

using namespace std;

string S;
int K;
int fail[500000];

int main(){

    cin >> S >> K;

    int j = 0;

    for(int i=1; i<S.length(); i++){
        while(j>0 && S[i]!=S[j]){
            j = fail[j-1];
        }
        if(S[i]==S[j]){
            fail[i] = ++j;
        }
    }

    cout << S.length() + (S.length()-fail[S.length()-1])*(K-1) << "\n";

    return 0;
}