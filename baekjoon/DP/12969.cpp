#include <iostream>

using namespace std;

int N, K;
// 30개중에 A,B가 몇개있는데
bool DP[31][31][31][436];
int A, B;
bool flag = false;
string ans = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

bool solve(int n, int a, int b, int k){
    if(DP[n][a][b][k] == true) return false;
    DP[n][a][b][k] = true;

    if(n==1){
        if(k==0){
            if(a+b==1){
                if(a==1) ans[n-1] = 'A';
                else ans[n-1] = 'B';
            }
            else if(a+b==0){
                ans[n-1] = 'C';
            }
            else return false;
            return true;
        }
        return false;
    }

    ans[n-1] = 'A';
    if(a-1>=0 && solve(n-1, a-1, b, k)) return true;

    ans[n-1] = 'B';
    if(k-a>=0 && b-1>=0 && solve(n-1, a, b-1, k-a)) return true;

    ans[n-1] = 'C';
    if(k-a-b>=0 && solve(n-1, a, b, k-a-b)) return true;

    return false;
}

int main(){
    cin >> N >> K;
    for(int a=0; a<=N && !flag; a++){
        for(int b=0; a+b<=N; b++){
            if(solve(N, a, b, K)){
                flag = true;
                for(int c=0; c<N; c++){
                    cout << ans[c];
                }
                cout << "\n";
                break;
            }
        }
    }

    if(!flag) cout << "-1\n";

    return 0;
}