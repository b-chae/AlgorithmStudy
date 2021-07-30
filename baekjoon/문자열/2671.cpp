#include <iostream>

using namespace std;

string str;

int main(){

    cin >> str;
    char pre = '?';
    bool start = false;
    bool end = false;
    str += "??";
    for(int i=0; i<str.length(); i++){
        cout << str[i] << " " << start << " " << end << " \n";
        if(!start && !end && str[i] == '0' && str[i+1] == '1'){
            i++;
            pre = '!';
            continue;
        }
        else if(!start && !end && str[i] == '1' && str[i+1] == '0' && str[i+2] == '0'){
            start = true;
        }
        else if(start && !end && str[i] == '0' && str[i+1] == '0'){
            i++;
            start = false;
            end = true;
        }
        else if(!start && end && pre == '0' && str[i] == '0'){
            ;
        }
        else if(!start && end && pre == '0' && str[i] == '1'){
            end = false;
        }
        else if(!start && !end && pre == '1' && str[i] == '1'){
            ;
        }
        else if(str[i] != '?'){
            cout << "NOISE\n";
            return 0;
        }
        pre = str[i];
    }

    if(!start && !end)
        cout << "SUBMARINE\n";
    else{
        cout << "NOISE\n";
    }
    return 0;
}