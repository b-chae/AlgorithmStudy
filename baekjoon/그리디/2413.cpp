#include <iostream>

using namespace std;

bool used[50001];
int check[50001];
int A[50000];
int N;

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    for(int i=1; i<=N; i++){
        check[i] = i;
    }

    for(int i=0; i<N; i++){
        int now = A[i];
        if(check[now] == now+1){
            cout << now+1 << " ";
            used[now] = true;
        }
        else if(now!=1 && check[now] == now && check[now-1] == now-1 && !used[now] && !used[now-1]){
            used[now-1] = true;
            cout << now-1 << " ";
            swap(check[now], check[now-1]);
        }
        else{
            used[now] = true;
            cout << now << " ";
        }
    }

    return 0;
}
