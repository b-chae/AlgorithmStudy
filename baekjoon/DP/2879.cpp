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
        //cout << A[i] << "\t";
    }

    int ans = 0;

    int prev = A[0];
    for(int i=1; i<N; i++){
        if(prev>=0){
            if(A[i]<0){
                ans += abs(prev);
            }
            else if(prev < A[i]){
                ;
            }
            else{
                ans += abs(prev-A[i]);
            }
            prev = A[i];
        }else{
            if(A[i]>=0){
                ans += abs(prev);
            }
            else if(prev > A[i]){
            }
            else{
                ans += abs(prev-A[i]);
            }
            prev = A[i];
        }
    }
    ans += abs(prev);
    cout << ans << "\n";

    return 0;
}