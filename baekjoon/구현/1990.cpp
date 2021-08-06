#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int A, B;
vector<int> pelindrome;

void solve(int n, string str){
    if(n>0 && n<=8){
        if(str[0] == '0'){
            ;
        }
        else if(A <= atoi(str.c_str()) && atoi(str.c_str()) <= B){
            pelindrome.push_back(atoi(str.c_str()));
        }
    }
    else if(n>8){
        return;
    }

    if(n==0){
        for(int i=0; i<=9; i++){
            solve(n+1, str + char(i+'0'));
        }
    }
    for(int i=0; i<=9; i++){
        solve(n+2, char(i+'0') + str + char(i+'0'));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin >> A >> B;

    solve(0, "");

    sort(pelindrome.begin(), pelindrome.end());
    for(int p:pelindrome){
        bool prime = true;
        for(int i=2; i<=floor(sqrt(p)); i++){
            if(p%i==0){
                prime = false;
                break;
            }
        }
        if(prime) cout << p << "\n";
    }

    cout << "-1\n";
    return 0;
}