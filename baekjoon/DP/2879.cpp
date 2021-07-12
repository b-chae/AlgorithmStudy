#include <iostream>

using namespace std;

int N;
int A[1000];

int main(){
    int x;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    for(int i=0; i<N; i++){
        cin >> x;
        A[i] = -A[i]+x;
        cout << A[i] << "\t";
    }

    int ans = 0;

    for(int i=0; i<N; i++){
        if(A[i]==0) continue;
        ans += abs(A[i]);
        for(int j=i+1; j<N; j++){
            if(A[i]*A[j] > 0){
                A[j]-=A[i];
            }
            else{
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}