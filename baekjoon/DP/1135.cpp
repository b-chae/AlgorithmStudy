#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ch[51];
bool visited[51];
int N;

int dfs(int n){
    if(ch[n].size()==0) return 0;
    
    int time[51];
    for(int i=0; i<ch[n].size(); i++){
        time[i] = dfs(ch[n][i]);
    }
    sort(time, time+ch[n].size());
    int res = 0;
    for(int i=0; i<ch[n].size(); i++){
        res = max(res, time[ch[n].size()-i-1]+i+1);
    }
    //cout << n << " " << max((int)ch[n].size()+mres, 1+res) << "\n";
    return res;
}

int main(){

    cin >> N;
    int x;
    cin >> x;
    for(int i=1; i<N; i++){
        cin >> x;
        ch[x].push_back(i);
    }

    cout << dfs(0) << "\n";
    return 0;
}