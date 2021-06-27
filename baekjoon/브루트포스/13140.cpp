#include <iostream>
#include <cmath>

using namespace std;

string alpha = "helowrd";
int idx[10] = {0,1,2,2,3,4,3,5,2,6};
int digit[11];
bool used[11];
int N;
bool flag = false;

void solve(int n){

    if(flag) return;
    if(n==7){

        int answer = 0;
        
        for(int i=0; i<5; i++){
            answer += digit[idx[i]]*pow(10, 4-i) + digit[idx[i+5]]*pow(10, 4-i);
        }

        if(answer == N){
            flag = true;

            cout << "  ";
            for(int i=0; i<5; i++){
                cout << digit[idx[i]];
            }
            cout << "\n+ ";
            for(int i=5; i<10; i++){
                cout << digit[idx[i]];
            }
            cout << "\n-------\n";
            printf("%7d\n", N);
        }

        return;   
    }

    for(int i=0; i<10; i++){
        if((n==0 || n==4) && i==0){
            continue;
        }

        if(!used[i]){
            digit[n] = i;
            used[i] = true;
            solve(n+1);
            used[i] = false;
        }
    }
}

int main(){

    cin >> N;

    solve(0);

    if(!flag){
        cout << "No Answer\n";
    }

    return 0;
}