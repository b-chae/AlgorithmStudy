#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long A[4000][4];
vector<long long> B;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<4; j++){
            cin >> A[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            B.push_back(A[i][2] + A[j][3]);
        }
    }

    sort(B.begin(), B.end());

    long long ans = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            long long now = A[i][0] + A[j][1];

            vector<long long>::iterator low = lower_bound(B.begin(), B.end(), -now);
            vector<long long>::iterator high = upper_bound(B.begin(), B.end(), -now);

            if(*low == -now){
                ans += high-low;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}