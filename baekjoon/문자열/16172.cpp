#include <iostream>

using namespace std;

string S, K;
int kmp[200000];
int D[200000];

int main(){
    cin >> S >> K;
    for(int i=0; i<K.length(); i++) kmp[i] = -1;

    int j=0;
    for(int i=1; i<K.length(); i++){
        while(K[j] != K[i] && j > 0){
            j = kmp[j-1];
        }

        if(K[j]==K[i]){
            kmp[i] = j++;
        }
    }

    if(S[0] == K[0]) D[0] = 1;

    j = 0;
    for(int i=0; i<S.length(); i++){
        if(S[i] >= '0' && S[i] <= '9'){
            D[i] = D[i-1];
            continue;
        }

        while(K[j] != S[i] && j > 0){
            j = kmp[j-1] + 1;
        }
        if(K[j] == S[i]) D[i]=++j;

        if(D[i] == K.length()){
            cout << "1\n";
            return 0;
        }
    }

    cout << "0\n";

    return 0;
}