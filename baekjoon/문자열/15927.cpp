#include <iostream>

using namespace std;

string str;

int main(){

    cin >> str;

    if(str[0] != str[str.length()-1]){
        cout << str.length() << "\n";
        return 0;
    }

    bool pelindrome = true;
    bool all_same = true;

    for(int i=0; i<str.length(); i++){
        if(str[i] != str[str.length()-1-i]) pelindrome = false;
        if(str[0] != str[i]) all_same = false;
    }

    if(!pelindrome){
        cout << str.length() << "\n";
    }
    else if(!all_same){
        cout << str.length() - 1 << "\n";
    }
    else{
        cout << "-1\n";
    }

    return 0;
}