#include <iostream>
#include <queue>

using namespace std;

struct node{
    int x, y, z, d;
};

int L, R, C;
string board[30][30];
bool visited[30][30][30];
int startL, startR, startC;
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp;

    while(true){
        cin >> L >> R >> C;

        if(L==0 && R==0 && C==0) break;

        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                cin >> board[i][j];
                for(int k=0; k<C; k++){
                    visited[i][j][k] = false;
                    if(board[i][j][k] == 'S'){
                        startL = i;
                        startR = j;
                        startC = k;
                    }
                }
            }
        }

        queue<node> bfsQueue;
        bfsQueue.push({startL, startR, startC, 0});
        visited[startL][startR][startC] = true;

        bool flag = false;

        while(!bfsQueue.empty()){
            int x = bfsQueue.front().x;
            int y = bfsQueue.front().y;
            int z = bfsQueue.front().z;
            int d = bfsQueue.front().d;
            bfsQueue.pop();

            if(board[x][y][z] == 'E'){
                flag = true;
                cout << "Escaped in " << d << " minute(s).\n";
                break;
            }

            for(int i=0; i<6; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if(nx >=0 && ny >= 0 && nz >= 0 && nx < L && ny < R && nz < C && board[nx][ny][nz] != '#' && !visited[nx][ny][nz]){
                    visited[nx][ny][nz] = true;
                    bfsQueue.push({nx, ny, nz, d+1});
                }
            }
        }
        if(!flag){
            cout << "Trapped!\n";
        }
    }

    return 0;
}
