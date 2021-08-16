#include <iostream>
#include <queue>

using namespace std;

int N, maxv;
long long total;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        total += a;
        maxv = max(maxv, a);
    }
    if (total - maxv > maxv) {
        cout << (total & 1);
    } else {
        cout << maxv - (total - maxv);
    }
    
    return 0;
}
