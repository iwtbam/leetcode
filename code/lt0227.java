import java.util.*;

class Solution {
    public int calculate(String s) {
        int count = 0;
        
        Map<Character, Integer> prior = new HashMap<>();
        
        Stack<Integer> nums = new Stack<>();
        Stack<Character> ops = new Stack<>();
        
        int state = 0;
        
        prior.put('+', 0);
        prior.put('-', 0);
        prior.put('*', 1);
        prior.put('/', 1);
        prior.put('#', -1);
        
        s = '#' + s + '#';
        
        
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c >= '0' && c <= '9'){
                count = count * 10 + c - '0';
                state = 1;
            }
            else{
                if(state == 1){
                    nums.push(count);
                    state = 0;
                    count = 0;
                }
                
                if(c == ' ')
                    continue;
                
                while(ops.size() > 0 && prior.get(c) <= prior.get(ops.peek())){
                    if(nums.size() < 2)
                        break;
                    int right = nums.pop();
                    int left = nums.pop();
                    nums.push(helper(left, right, ops.pop()));
                }
                
                ops.push(c);
            }
        }
        
        
        return nums.peek();
    }
    
    public int helper(int leftNum, int rightNum, char op){
        switch(op){
            case '+':
                return leftNum + rightNum;
            case '-':
                return leftNum - rightNum;
            case '*':
                return leftNum * rightNum;
            case '/':
                return leftNum / rightNum;
        }
        return UN_PARSE;
    }
    
    private final int UN_PARSE = Integer.MAX_VALUE / 2;
}