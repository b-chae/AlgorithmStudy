#include <iostream>
using namespace std;
int N;
string b[100];
bool v[2][100][100];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
#define f for(i=0;i<N;i++){
void dfs(int i, int j, int n){
    v[n][i][j]=1;
    for(int x=0;x<4;x++){
        int nx=i+dx[x];
        int ny=j+dy[x];
        if(nx<0||ny<0||nx>=N||ny>=N||v[n][nx][ny]) continue;
        if(b[i][j]==b[nx][ny]||(n==1&&(b[i][j]=='R'||b[i][j]=='G')&&(b[nx][ny]=='R'||b[nx][ny]=='G')))dfs(nx,ny,n);
    }
}
int main(){
    cin>>N;
    int i,j,k,c[2]={0,0};
    f cin>>b[i];}
    f for(j=0;j<N;j++){
    for(k=0;k<2;k++){
        if(!v[k][i][j]){
            dfs(i,j,k);
            c[k]++;}}}}
    cout<<c[0]<<" "<<c[1]<<"\n";
    return 0;
}
