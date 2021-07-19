#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
list< pair<int, int> > q[100];
list< pair<int, int> > total;
vector< pair<int, int> > waiting;

int N;

pair<int, int> string_strip(string s){
    pair<int, int> res;
    res.first = s[0] - 'A';
    int num = 0;
    for(unsigned int i=2; i<s.length() && s[i] >= '0' && s[i] <= '9'; i++){
        num = num*10 + s[i] - '0';
    }
    res.second = num;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp;

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++){
            cin >> tmp;
            q[i].push_back(string_strip(tmp));
            total.push_back(string_strip(tmp));
        }
    }

    total.sort();

    bool flag = true;

    while(!total.empty() && flag){

        // cout << (char)(total.front().first + 'A') << " " << total.front().second << "\n";
        // for(int i=0; i<waiting.size(); i++){
        //     cout << (char)(waiting[i].first + 'A') << "/" << waiting[i].second << " ";
        // }
        // cout << "\n";

        flag = false;
        pair<int, int> biggest = make_pair(0, 0);

        if(!waiting.empty() && waiting.back() == total.front()){
            waiting.pop_back();
            total.pop_front();
            flag = true;
            continue;
        }

        for(int i=0; i<N; i++){
            if(q[i].empty()) continue;

            if(total.front() == q[i].front()){
                q[i].pop_front();
                total.pop_front();
                flag = true;
            }
            else{
                waiting.push_back(q[i].front());
                q[i].pop_front();
                flag = true;
            }
            break;
        }
    }

    if(total.empty()){
        cout << "GOOD\n";
    }
    else{
        cout << "BAD\n";
    }


    return 0;
}