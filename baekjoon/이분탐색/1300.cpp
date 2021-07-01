#include <iostream>

using namespace std;

int N, K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    int left = 1, right = 1000000000;
    int middle;
    int ans;

    while(left <= right){
        middle = (left+right)/2;

        int count = 0;
        for(int i=1; i<=N; i++){
            count += min(N, middle/i);
        }
        //cout << middle << " " << count << "\n";
        if(count >= K){
            ans = middle;
            right = middle-1;
        }
        else{
            left = middle+1;
        }
    }

    cout << ans << "\n";

    return 0;
}