#include <iostream>
#include <vector>

using namespace std;

#define INF 200001

int N, M, K;
int F[201][201];
vector<int> friends;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            F[i][j] = INF;
        }
        F[i][i] = 0;
    }


    for(int i=0; i<M; i++){
        int x, y, z;
        cin >> x >> y >> z;
        F[x][y] = z;
    }

    cin >> K;
    for(int i=0; i<K; i++){
        int x;
        cin >> x;
        friends.push_back(x);
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(F[i][j] > F[i][k] + F[k][j]){
                    F[i][j] = F[i][k] + F[k][j];
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << F[i][j] << "\t";
        }
        cout << "\n";
    }

    vector<int> ans;
    int minsum = INF * 400;

    for(int i=1; i<=N; i++){
        bool flag = true;
        int tmp = 0;
        for(int j:friends){
            if(F[i][j] == INF || F[j][i] == INF){
                flag = false;
                break;
            }
            tmp = max(tmp, F[i][j] + F[j][i]);
        }

        if(!flag) continue;

        if(minsum > tmp){
            ans.clear();
            ans.push_back(i);
            minsum = tmp;
        }
        else if(minsum == tmp){
            ans.push_back(i);
        }
    }

    for(int a:ans){
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}