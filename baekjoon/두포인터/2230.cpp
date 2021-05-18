#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long A[100000];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 2000000000;

    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    sort(A, A+N);

    int left = 0, right = 0;
    int now = 0;

    while(left < N && right < N && left <= right){

        now = A[right] - A[left];

        if(now < M){
            right++;
        }
        else{
            ans = min(ans, now);
            left++;
        }
    }

    cout << ans << "\n";
    return 0;
}
