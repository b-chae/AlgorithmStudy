#include <iostream>

using namespace std;

int D, N;
int A[300000];
int B[300000];
int M[300000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> D >> N;

    for(int i=0; i<D; i++){
        cin >> A[i];
    }

    for(int j=0; j<N; j++){
        cin >> B[j];
    }

    M[0] = A[0];

    for(int i=1; i<D; i++){
        M[i] = min(A[i], M[i-1]);
    }
   
    int now = 0;
    int last = 0;
    for(int i=D-1; i>=0; i--){
        if(now<N && M[i] >= B[now]){
            now++;
            last = i;
        }
    }

    if(now==N) cout << last+1 << "\n";
    else cout << "0\n";

    return 0;
}