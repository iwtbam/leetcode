import java.util.*;

class Solution {
    public int[] dailyTemperatures(int[] T) {
        
        int[] res = new int[T.length];
        Stack<Integer> record = new Stack<>();
        for(int i = T.length - 1; i >= 0; i--){
            while(record.size() > 0 && T[i] >= T[record.peek()])
                record.pop();
            res[i] = record.size() == 0 ? 0 : record.peek() - i;
            record.push(i);
        }
        
        return res;
    }
}