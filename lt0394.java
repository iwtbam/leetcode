import java.util.*;

class Solution {
    public String decodeString(String s) {
        StringBuffer sb = new StringBuffer();
        int num = 0;
        Stack<Integer> nums = new Stack<Integer>();
        Stack<String>  strs = new Stack<String>();
        
        for(Character c: s.toCharArray()){
            if(c == '['){
                nums.push(num);
                strs.push(sb.toString());
                num = 0;
                sb = new StringBuffer();
            }else if(c == ']'){
                StringBuffer temp = new StringBuffer();
                int repeat = nums.pop();
                for(int i = 0; i < repeat; i++)
                    temp.append(sb);
                sb = new StringBuffer(strs.pop() + temp);
            }else if( c >= '0' && c <= '9'){
                num = num * 10 + c - '0';
            }else
                sb.append(c);
        }
        
        return sb.toString();
    }
               
}