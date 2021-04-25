#include <iostream>

using namespace std;

int main(){
    int N;
    string str;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str;

        while(str.length() > 1){
            cout << str << "\n";
            if(str.substr(str.length()-2, 2) == "01" && (str.length() == 2 || str[str.length()-3] == '1')){
                str = str.substr(0, str.length() - 2);
            }
            else{
                bool start = false, end = false;
                int count = 0;
                int idx = str.length()-1;

                while(idx>=0 && str[idx] == '1'){
                    idx--;
                    end = true;
                }

                for(; idx>=0; idx--){
                    if(str[idx] == '0') count++;
                    else break;
                }

                if(idx>=0 && str[idx] == '1') start = true;
                if(start && end && count >=2){
                    str = str.substr(0, idx);
                }
                else break;
            }
        }

        if(str.length() > 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }

    return 0;
}
