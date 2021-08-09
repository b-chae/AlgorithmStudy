#include <iostream>

using namespace std;

int N;
string str;

int op(int x, int y, char c){
    if(c=='+') return x+y;
    else if(c=='-') return x-y;
    else return x*y;
}

int solve(int idx, int tmp){

    if(idx>=N) return tmp;

    int res = -2147483647;

    int y = str[idx+1] - '0';
    res = max(res, solve(idx+2, op(tmp, y, str[idx])));

    if(idx+4 <= N){
        int z = str[idx+3] - '0';
        res = max(res, solve(idx+4, op(tmp, op(y, z, str[idx+2]), str[idx])));
    }

    cout << res << "\n";
    return res;
}

int main(){

    cin >> N;
    cin >> str;
    cout << solve(1, str[0]-'0') << "\n";

    return 0;
}