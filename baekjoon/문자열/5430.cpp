#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
string command;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int t=0;t<T;t++){

        bool flag = true;
        bool reverse = false;

        cin >> command;
        cin >> N;
        string tmp;
        cin >> tmp;
        list<int> mylist;

        int key = 0;

        for(int i=1; tmp[i] != ']'; i++){
            if(tmp[i] >= '0' && tmp[i] <= '9'){
                key = key*10 + tmp[i]-'0';
            }
            else if(tmp[i] == ','){
                mylist.push_back(key);
                key = 0;
            }
        }

        if(key!=0) mylist.push_back(key);

        for(int i=0; i<command.length(); i++){
            if(command[i] == 'R'){
                if(reverse) reverse = false;
                else reverse = true;
            }
            else{
                if(mylist.size() <= 0){
                    cout << "error\n";
                    flag = false;
                    break;
                }
                list<int>::iterator it;
                if(!reverse){
                    it = mylist.begin();
                }
                else{
                    it = mylist.end();
                    it--;
                }
                it = mylist.erase(it);
            }
        }

        if(!flag) continue;
        vector<int> ans;
        for (int const &c: mylist) {
            ans.push_back(c);
        }

        cout << "[";
        if(!reverse){
            for(int i=0; i<ans.size(); i++){
                cout << ans[i];
                if(i!=ans.size()-1) cout << ",";
            }
        }
        else{
            for(int i=ans.size()-1; i>=0; i--){
                cout << ans[i];
                if(i!=0) cout << ",";
            }
        }
        cout << "]\n";
    }
    return 0;
}
