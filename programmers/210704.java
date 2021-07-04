import java.util.Arrays;

class Solution {
    public int solution(int[] prices, int[] discounts) {
        int answer = 0;
        int idx = discounts.length-1;
        
        Arrays.sort(prices);
        Arrays.sort(discounts);
        
        for(int p=prices.length-1; p>=0; p--){
            if(idx>=0){
                answer += prices[p]*(100-discounts[idx])/100;
                idx--;
            }
            else {
                answer += prices[p];
            }
        }
        return answer;
    }
}


import java.util.*;

class Solution {
    public String[] solution(String s) {
        //String[] answer = {};
        List<String> answer = new LinkedList<String>();
        
        int leftlow = 0, lefthigh = 0;
        int rightlow = s.length()-1, righthigh = s.length()-1;
        int now = 0;
        
        while(leftlow<=rightlow){
            if(s.substring(leftlow, lefthigh+1).equals(s.substring(rightlow, righthigh+1))){
                
                //System.out.println(s.substring(leftlow, lefthigh+1));
                if(leftlow != rightlow){
                    answer.add(now, s.substring(leftlow, lefthigh+1));
                    answer.add(answer.size()-now, s.substring(leftlow, lefthigh+1));
                    now++;
                }
                else
                    answer.add(now, s.substring(leftlow, lefthigh+1));
                
                leftlow = lefthigh+1;
                lefthigh = leftlow;
                righthigh = rightlow-1;
                rightlow = righthigh;
            }
            else{
                lefthigh++;
                rightlow--;
            }
        }
        
        return answer.toArray(new String[0]);
    }
}

import java.util.*;

public class Solution {
    public int solution(String s, String t) {
        int result = 0;
        
        Stack<Integer> stack = new Stack<>();
        
        for(int i=0; i<s.length(); i++){

            if(stack.empty()){
                if(s.charAt(i) == t.charAt(0)){
                    stack.push(0);
                }
                else stack.push(-1);
            }
            else{
                if(s.charAt(i) == t.charAt(stack.peek() + 1)){
                    stack.push(stack.peek()+1);
                }
                else{
                    if(s.charAt(i) == t.charAt(0)){
                        stack.push(0);
                    }
                    else stack.push(-1);
                }
            }
            
            if(stack.peek() == t.length()-1){
                for(int j=0; j<t.length(); j++){
                    stack.pop();
                }
                result++;
            }
        }
        
        return result;
    }
}