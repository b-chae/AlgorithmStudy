#include <iostream>

using namespace std;

int N;
int x = -1000000000, y = -1000000000;
int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int i, j;
    for(int k=0; k<N; k++){
        cin >> i >> j;

        if(i <= y && j <= y) continue;
        if(i <= y){
            y=j;
        }
        else{
            ans += y-x;
            x = i;
            y = j;
        }
    }

    ans += y-x;
    cout << ans << "\n";

    return 0;
}