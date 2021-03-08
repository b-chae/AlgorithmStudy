#include <string>
#include <vector>

using namespace std;

#define INF 2100000000

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i=1; i<= n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    
    for(vector<int> fare: fares){
        dist[fare[0]][fare[1]]=fare[2];
        dist[fare[1]][fare[0]]=fare[2];
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if((long long)dist[i][j] > (long long)dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    answer = dist[s][a] + dist[s][b];
    
    for(int i=1; i<=n; i++){
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}
