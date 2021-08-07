#include <iostream>

using namespace std;

string str;
bool notprime[100000];

int main(){

    notprime[0] = true;
    notprime[1] = true;

    for(int i=2; i<100000; i++){
        if(notprime[i]) continue;

        for(int j=2; i*j<100000; j++){
            if(!notprime[i*j]){
                notprime[i*j] = true;
            }
        }
    }

    while(true){
        cin >> str;
        if(str=="0")  break;

        int ans = 0;

        for(int i=0; i<str.length(); i++){
            int n = atoi(new char(str[i]));
            if(!notprime[n]) ans = max(ans, n);
        }

        for(int i=0; i<str.length()-1; i++){
            int n = atoi(str.substr(i, 2).c_str());
            if(!notprime[n]) ans = max(ans, n);
        }

        for(int i=0; i<str.length()-2; i++){
            int n = atoi(str.substr(i, 3).c_str());
            if(!notprime[n]) ans = max(ans, n);
        }

        for(int i=0; i<str.length()-3; i++){
            int n = atoi(str.substr(i, 4).c_str());
            if(!notprime[n]) ans = max(ans, n);
        }

        for(int i=0; i<str.length()-4; i++){
            int n = atoi(str.substr(i, 5).c_str());
            if(!notprime[n]) ans = max(ans, n);
        }

        cout << ans << "\n";
    }

    return 0;
}