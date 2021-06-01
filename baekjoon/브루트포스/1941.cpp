#include <iostream>
#include <queue>

using namespace std;

bool include[5][5];
string board[5];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans;

bool adjacent(){
    bool visited[5][5];

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            visited[i][j] = false;
        }
    }

    queue < pair <int, int> > q;
    for(int i=0; i<5 && q.empty(); i++){
        for(int j=0; j<5; j++){
            if(include[i][j]){
                q.push(make_pair(i,j));
                visited[i][j] = true;
                break;
            }
        }
    }

    int count = 1;

    while(!q.empty() && count < 7){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny >=0 && nx < 5 && ny < 5 && !visited[nx][ny] && include[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
                count++;
            }
        }
    }

    if(count == 7)return true;
    return false;
}

void brute(int i, int j, int selected, int y, int s){
    if(selected == 7){
        if(y<s && adjacent()){
            ans++;
        }
        return;
    }

    if(j>=5){
        i++;
        j=0;
    }

    if(i>=5){
        return;
    }

    int ny = y;
    int ns = s;

    include[i][j] = true;
    if(board[i][j] == 'Y') ny++;
    else ns++;
    brute(i, j+1, selected+1, ny, ns);
    include[i][j] = false;
    brute(i, j+1, selected, y, s);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++) cin >> board[i];

    brute(0, 0, 0, 0, 0);

    cout << ans << "\n";

    return 0;
}