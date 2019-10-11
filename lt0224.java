import java.util.*;

class Solution {
    public int calculate(String s) {
         Stack<Character> ops = new Stack<>();
         Stack<Integer> nums = new Stack<>();
         Map<Character, Integer> por = new HashMap<>();
         int state = 0;
         s = '(' + s + ')';
         por.put('(', 2);
         por.put('+', 1);
         por.put('-', 1);
         por.put(')', 0);
         
         int num = 0;
         for(int i = 0; i < s.length(); i++){
             char c = s.charAt(i);
             if(c >= '0' && c <= '9'){
                 num = num * 10 + (c - '0');
                 state = 1;
             }else{
                 
                 if(state == 1){
                     state = 0;
                     nums.push(num);
                     num = 0;
                 }
                 
                 if(c == ' ')
                     continue;
                 
                 
                 if(c == '('){
                     ops.push('(');
                 }else{
                     while(ops.size() > 1 && por.get(c) <= por.get(ops.peek())){
                         char topOp = ops.peek();
                         
                         if(topOp == '('){
                             if(c == ')')
                                 ops.pop();
                             break;   
                         }
                         
                         
                         int right = nums.pop();
                         int left = nums.pop();
                         nums.push(helper(left, right, topOp));
                         ops.pop();
                     }
                     if(c!=')')
                         ops.push(c);
                     
                         
                 }
             }
         }
         return nums.peek();
     }
     
     public int helper(int leftOp, int rightOp, char op){
         switch(op){
             case '-':
                 return leftOp - rightOp;
             case '+':
                 return leftOp + rightOp;
             default:
                 return 0;
         }
     }
 }