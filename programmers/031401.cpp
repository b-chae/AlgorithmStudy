#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int kx = key.size();
    int ky = key[0].size();
    int lx = lock.size();
    int ly = lock[0].size();
    
    int tmp[20][20];
    int check[20][20];
    
    for(int t=0; t<4 && !answer; t++){
        for(int x = -kx+1; x < lx && !answer; x++){
            for(int y = -ky+1; y < ly && !answer; y++){

                bool flag = true;
                
                for(int i=0; i<lx; i++){
                    for(int j=0; j<ly; j++){
                        check[i][j] = lock[i][j];
                    }
                }

                for(int m = 0; m<kx && flag; m++){
                    for(int n=0; n<ky && flag; n++){
                        int a = x+m;
                        int b = y+n;
                        if(a>=0 && b>=0 && a < lx && b < ly){
                            if(key[m][n]==0 && lock[a][b] == 0){
                                flag = false;
                            }
                            else if(key[m][n]==1 && lock[a][b] == 1){
                                flag = false;
                            }
                            else if(key[m][n]==1){
                                check[a][b] = 1;
                            }
                        }
                    }
                }

                if(flag){
                    bool flag2 = true;
                    for(int i=0; i<lx && flag2; i++){
                        for(int j=0; j<ly && flag2; j++){
                            if(check[i][j] == 0){
                                flag2=false;
                            }
                        }
                    }
                    if(flag2) answer=true;
                }   
            }
        }
        
        
        for(int i=0; i<kx; i++){
            for(int j=0; j<ky; j++){
                tmp[ky-j-1][i] = key[i][j];
            }
        }
        
        for(int i=0; i<ky; i++){
            for(int j=0; j<kx; j++){
                key[i][j] = tmp[i][j];
            }
        }
    
        swap(kx, ky);
    }
    
    return answer;
}
