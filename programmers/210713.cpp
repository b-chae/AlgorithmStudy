#include <vector>
#include <iostream>

using namespace std;

int solution(int money, int minratio, int maxratio, int ranksize, int threshold, int months){
    for(int i=0; i<months; i++){
        int tmp = money / 100 * 100;
        if(tmp < threshold) continue;
        int ratio = minratio + (tmp-threshold)/ranksize;
        if(ratio > maxratio) ratio = maxratio;
        money = money - tmp / 100 * ratio;
    }
    return money;
}

vector<int> solution(int rows, int columns, vector<vector <int> > swipes){
    vector<int> answer;
    int board[51][51];
    int k = 1;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            board[i][j] = k++;
        }
    }

    for(vector<int> swipe: swipes){
        int ans = 0;
        int dir = swipe[0];
        if(dir == 1){
            for(int j=swipe[2]; j<=swipe[4]; j++){
                int tmp = board[swipe[3]][j];
                for(int i=swipe[3]; i>swipe[1]; i--){
                    board[i][j] = board[i-1][j];
                }
                board[swipe[1]][j] = tmp;
                ans += tmp;
            }
        }
        else if(dir == 2){
            for(int j=swipe[2]; j<=swipe[4]; j++){
                int tmp = board[swipe[1]][j];
                for(int i=swipe[1]; i<swipe[3]; i++){
                    board[i][j] = board[i+1][j];
                }
                board[swipe[3]][j] = tmp;
                ans += tmp;
            }
        }
        else if(dir == 3){
            for(int i=swipe[1]; i<=swipe[3]; i++){
                int tmp = board[i][swipe[4]];
                for(int j=swipe[4]; j>swipe[2]; j--){
                    board[i][j] = board[i][j-1];
                }
                board[i][swipe[2]] = tmp;
                ans += tmp;
            }
        }
        else{
            for(int i=swipe[1]; i<=swipe[3]; i++){
                int tmp = board[i][swipe[2]];
                for(int j=swipe[2]; j<swipe[4]; j++){
                    board[i][j] = board[i][j+1];
                }
                board[i][swipe[4]] = tmp;
                ans += tmp;
            }
        }
        answer.push_back(ans);
    }

    return answer;
}

int solution(string line1, string line2){
    int answer = 0;
    if(line2.length() == 1){
        for(int i=0; i<line1.length(); i++){
            if(line1[i] == line2[0]) answer++;
        }
        return answer;
    }

    for(int i=0; i<=line1.length()-line2.length(); i++){
        for(int j=1; j<line1.length() && i+j*(line2.length()-1)<line1.length(); j++){
            bool flag = true;
            for(int k=0; k<line2.length(); k++){
                if(line1[i+j*k]!=line2[k]){
                    flag = false;
                    break;
                }
            }
            if(flag) answer++;
        }
    }
    return answer;
}

#include <queue>

struct node{
    long long age;
    int num, type;
    bool operator<(const struct node& a) const{
        if(age == a.age){
            return num > a.num;
        }
        return age > a.age;
    }
};

priority_queue<node> pq;
vector<pair<int, int>> edges[100001];
int degree[100001];
bool off[100001];

vector<int> solution(vector<long long> ages, vector<vector<int>> wires){
    vector<int> answer;

    for(int i=1; i<=ages.size(); i++){
        pq.push({ages[i-1], i, 1});
    }

    for(vector<int> wire : wires){
        edges[wire[0]].push_back({wire[1], wire[2]});
        degree[wire[1]]++;
    }

    while(!pq.empty()){
        long long age = pq.top().age;
        int now = pq.top().num;
        int type = pq.top().type;
        pq.pop();

        if(off[now]) continue;
        if(type==1){
            off[now]=true;
            answer.push_back(now);

            for(pair<int, int> edge: edges[now]){
                if(!off[edge.first]){
                    pq.push({age+edge.second, edge.first, 2});
                }
            }
        }
        else{
            degree[now]--;
            if(degree[now]==0){
                off[now]=true;
                answer.push_back(now);

                for(pair<int, int> edge: edges[now]){
                    if(!off[edge.first]){
                        pq.push({age+edge.second, edge.first, 2});
                    }
                }
            }
        }
    }

    return answer;
}