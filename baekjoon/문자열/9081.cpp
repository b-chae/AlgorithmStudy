#include <iostream>
#include <vector>

using namespace std;

vector<string> stack;
int T;
string word[10];
int alpha[26];
int total = 0;
bool final = false;

int solve(int now, int n, string s, bool flag){

    if(final) return 0;

    if(n == word[now].length()){
        if(flag){
            stack.push_back(s);
            total++;
            final = true;
            return 1;
        }
        return 0;
    }

    int res = 0;
    for(int i=0; i<26; i++){
        if(alpha[i] > 0){
            if(!flag && word[now][n] - 'A' <= i){
                alpha[i]--;
                res += solve(now, n+1, s+char('A'+i), word[now][n]-'A' != i);
                alpha[i]++;
            }
            else if(flag){
                alpha[i]--;
                res += solve(now, n+1, s+char('A'+i), true);
                alpha[i]++;
            }
        }
    }

    return res;
}

int main(){

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> word[i];
        for(int j=0; j<26; j++){
            alpha[j] = 0;
        }
        for(unsigned int j=0; j<word[i].length(); j++){
            alpha[word[i][j]-'A']++;
        }
        total = 0;
        final = false;
        stack.clear();
        solve(i, 0, "", false);
        
        if(stack.size()>0){
            cout << stack[0] << "\n";
        }
        else{
            cout << word[i] << "\n";
        }
    }

    return 0;
}