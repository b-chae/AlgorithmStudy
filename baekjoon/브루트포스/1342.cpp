#include <iostream>

using namespace std;

int countA[26];
long long ans = 0;
string str;

void solve(int n, string s){
    if(n==str.length()){
        ans++;
        return;
    }

    for(int i=0; i<26; i++){
        if(s.length()==0 || s[s.length()-1] != char(i+'a'))
        if(countA[i]>0){
            countA[i]--;
            solve(n+1, s+(char)(i+'a'));
            countA[i]++;
        }
    }
}

int main(){

    cin >> str;

    for(int i=0; i<str.length(); i++){
        countA[str[i]-'a']++;
    }

    solve(0, "");
    cout << ans << "\n";

    return 0;
}