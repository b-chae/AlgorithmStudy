#include <iostream>

using namespace std;

int N, M;
bool isOpen[21];
int T[21];

int solve(int n, int ans){
    if(n==M) return ans;

    int x, y;
    for(int i=1; i<=N; i++){
        if(isOpen[i]){
            x=i;
            break;
        }
    }

    for(int i=x+1; i<=N; i++){
        if(isOpen[i]){
            y=i;
            break;
        }
    }

    if(T[n] == x || T[n] == y) return solve(n+1, ans);
    if(T[n] < x){
        isOpen[x] = false;
        isOpen[T[n]] = true;

        int res = solve(n+1, ans + x-T[n]);
        isOpen[x] = true;
        isOpen[T[n]] = false;
        return res;
    }
    if(T[n] > y){
        isOpen[y] = false;
        isOpen[T[n]] = true;

        int res = solve(n+1, ans + T[n]-y);
        isOpen[y] = true;
        isOpen[T[n]] = false;
        return res;
    }

    int d1, d2;

    isOpen[x] = false;
    isOpen[T[n]] = true;
    d1 = solve(n+1, ans + T[n]-x);
    isOpen[x] = true;
    isOpen[y] = false;
    d2 = solve(n+1, ans + y - T[n]);
    if(d1 < d2){
        isOpen[x] = true;
        isOpen[T[n]] = false;
        return d1;
    }
    else{
        isOpen[y] = true;
        isOpen[T[n]] = false;
        return d2;
    }
}

int main(){
    cin >> N;

    int x;
    for(int i=0; i<2; i++){
        cin >> x;
        isOpen[x] = true;
    }

    cin >> M;

    for(int i=0; i<M; i++){
        cin >> T[i];
    }

    cout << solve(0, 0) << "\n";


    return 0;
}