#include <iostream>

using namespace std;

int check[15];
int N;
int ans = 0;

void solve(int n){

    if(n==N){
        ans++;
        return;
    }

    bool possible[15];
    for(int i=0; i<N; i++) possible[i] = true;
    for(int i=0; i<n; i++){
        possible[check[i]]=false;
        if(check[i]+(n-i)<N)
        possible[check[i]+(n-i)]=false;
        if(check[i]-(n-i)>=0)
        possible[check[i]-(n-i)]=false;
    }
    for(int i=0; i<N; i++){
        if(possible[i]){
            check[n] = i;
            solve(n+1);
        }
    }
}

int main(){

    cin >> N;
    solve(0);
    cout << ans << "\n";

    return 0;
}