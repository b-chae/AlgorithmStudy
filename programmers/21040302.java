class Solution {
    
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {0,0};
        int c0 = 0, right = 0, wrong = 0;
        for(int i=0; i<6; i++){
            boolean flag = false;
            for(int j=0; j<6; j++){
                if(lottos[i] == win_nums[j]){
                    flag = true;
                    break;
                }
            }
            if(lottos[i] == 0) c0++;
            else if(flag) right++;
            else wrong++;
        }
        
        answer[0] = right + c0;
        answer[1] = right;
        
        for(int i=0; i<2; i++){
            if(answer[i] == 6) answer[i] = 1;
            else if(answer[i] == 5) answer[i] = 2;
            else if(answer[i] == 4) answer[i] = 3;
            else if(answer[i] == 3) answer[i] = 4;
            else if(answer[i] == 2) answer[i] = 5;
            else answer[i] = 6;
        }
        return answer;
    }
}

class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        int[][] board = new int[rows][];
        for(int i=0; i<rows; i++){
            board[i] = new int[columns];
        }
        int n=1;
        for(int i=0;i<rows; i++){
            for(int j=0;j<columns; j++){
                board[i][j] = n++;
            }
        }
        
        for(int i=0;i<queries.length;i++){
            int[][] temp = new int[100][100];
            int x1 = queries[i][0];
            int y1 = queries[i][1];
            int x2 = queries[i][2];
            int y2 = queries[i][3];
            
            for(int y=y1; y<y2; y++){
                temp[x1-1][y] = board[x1-1][y-1];
            }
            for(int x=x1; x<x2; x++){
                temp[x][y2-1] = board[x-1][y2-1];
            }
            for(int y=y2-2; y>=y1-1; y--){
                temp[x2-1][y] = board[x2-1][y+1];
            }
            for(int x=x2-2; x>=x1-1; x--){
                temp[x][y1-1] = board[x+1][y1-1];
            }
            
            int a = 100000000;
            for(int x=0; x<rows; x++){
                for(int y=0; y<columns; y++){
                    if(temp[x][y] != 0){
                        board[x][y] = temp[x][y];
                        a = Math.min(a, temp[x][y]);
                    }
                }
            }
            answer[i] = a;
            
        }
        
        return answer;
    }
}

import java.util.Map;
import java.util.HashMap;
class Solution {
    private int[] answer;
    private int[] p;
    private Map<String, Integer> name;
    
    void check(int n, int money){
        if(n==-1) return;
        if(money < 10){
            answer[n] += money;
        }
        else{
            int temp = (int)(money*0.1);
            answer[n] += money - temp;
            check(p[n], temp);
        }
    }
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        answer = new int[enroll.length];
        p = new int[enroll.length];
        name = new HashMap<>();
        
        name.put("-", -1);
        for(int i=0; i<enroll.length; i++){
            name.put(enroll[i], i);
        }
        for(int i=0; i<referral.length; i++){
            p[i] = name.get(referral[i]);
        }
        
        for(int i=0; i<seller.length; i++){
            int se = name.get(seller[i]);
            int am = amount[i];
            check(se, am*100);
        }
        
        return answer;
    }
}
