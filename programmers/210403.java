class Solution {
    
    private int[] gift = new int[100001];

    public int solution(int[] gift_cards, int[] wants) {
        int answer = 0;
        
        for(int i=0; i<gift_cards.length; i++){
            gift[gift_cards[i]]++;
        }
        for(int i=0; i<wants.length; i++){
            if(gift[wants[i]] > 0){
                gift[wants[i]]--;
                answer++;
            }
        }
        
        return gift_cards.length - answer;
    }
}

class Solution {
    private boolean[] include= new boolean[16];
    
    public int solve(int n, int selected, int r, int[][] needs){
        if(n == needs[0].length && selected == r){
            int count = 0;
            for(int i=0; i<needs.length; i++){
                boolean flag = true;
                for(int j=0; j<needs[i].length; j++){
                    if(needs[i][j] == 1 && !include[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) count++;
            }
            return count;
        }
        if(n == needs[0].length) return 0;
        
        include[n] = true;
        int res1 = solve(n+1, selected+1, r, needs);
        include[n] = false;
        int res2 = solve(n+1, selected, r, needs);
        return Math.max(res1, res2);
    }
    
    public int solution(int[][] needs, int r) {
        int answer = 0;
        answer = solve(0, 0, r, needs);
        return answer;
    }
}

import java.util.List;
import java.util.ArrayList;
import java.util.PriorityQueue;

class Solution {
    private boolean[] visited = new boolean [100001];
    private int[] dist = new int[100001];
    private ArrayList<Integer> vec[] = new ArrayList[100001];
    
    private void dfs(int n, int k, int[] passenger){
        visited[n] = true;
        dist[n] = k;
        for(int next : vec[n]){
            if(!visited[next]){
                dfs(next, k+passenger[next-1], passenger);
            }
        }
    }
    
    public int[] solution(int n, int[] passenger, int[][] train) {
        int[] answer = {0, 0};
        
        for(int i=1; i<=n; i++){
            vec[i] = new ArrayList<Integer>();
            visited[i] = false;
        }
        for(int i=0; i<train.length; i++){
            vec[train[i][0]].add(train[i][1]);
            vec[train[i][1]].add(train[i][0]);
        }
        
        dfs(1, passenger[0], passenger);
        int maxcount = 0;
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] >= maxcount){
                maxcount = dist[i];
                maxi = i;
            }
        }
        answer[0] = maxi;
        answer[1] = maxcount;
        
        return answer;
    }

}
