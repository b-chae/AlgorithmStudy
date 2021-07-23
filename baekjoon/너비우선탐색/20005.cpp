#include <iostream>
#include <queue>

using namespace std;

struct node{
    int x, y, n, c;
};

int N, M, P;
string board[1000];
queue<node> q;
int dps[26];
int hp;
bool attack[26];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool visited[1000][1000][26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> P;
    for(int i=0; i<N; i++){
        cin >> board[i];
        for(int j=0; j<M; j++){
            if(board[i][j] >= 'a' && board[i][j] <= 'z'){
                q.push({i,j,0,board[i][j]-'a'});
                visited[i][j][board[i][j]-'a']=true;
            }
        }
    }
    char tmp;
    for(int i=0; i<P; i++){
        cin >> tmp;
        cin >> dps[tmp-'a'];
    }
    cin >> hp;

    int finaln = -1;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int n = q.front().n;
        int c = q.front().c;
        q.pop();

        if(finaln != -1 && n > finaln) break;

        if(board[x][y] == 'B'){
            attack[c] = true;
            hp -= dps[c];
            q.push({x,y,n+1,c});

            if(hp <= 0){
                finaln = n;
            }
            continue;
        }

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M || board[nx][ny]=='X' || visited[nx][ny][c]) continue;
            q.push({nx,ny,n+1,c});
            visited[nx][ny][c]=true;
        }
    }

    int count = 0;
    for(int i=0; i<26; i++){
        if(attack[i]) count++;
    }
    cout << count << "\n";

    return 0;
}