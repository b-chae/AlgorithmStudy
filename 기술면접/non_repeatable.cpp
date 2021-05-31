/*
문자열에서 반복되지 않는 첫번째 문자를 찾아내는 효율적인 함수를 작성하여라. • “total” => “o” • “teeter” => “r”
*/

#include <iostream>
#include <queue>

using namespace std;

int count[26];

int main(){

    string str;

    cin >> str;

    for(int i=0; i<str.length(); i++){
        count[str[i]-'a']++;
    }

    for(int i=0; i<str.length(); i++){
        if(count[str[i]-'a']==1){
            cout << str[i];
            break;
        }
    }

    return 0;
}