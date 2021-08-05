#include <iostream>

using namespace std;

int N;
string str;
int alpha[26];

void solve(int n, string s){

    if(n==str.length()){
        cout << s << "\n";
        return;
    }

    for(int i=0; i<26; i++){
        if(alpha[i] > 0){
            alpha[i]--;
            solve(n+1, s + (char)('a'+i));
            alpha[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int n=0; n<N; n++){
        cin >> str;
        for(int i=0; i<26; i++)
            alpha[i] = 0;

        for(int i=0; i<str.length(); i++){
            alpha[str[i]-'a']++;
        }

        solve(0, "");
    }
    return 0;
}