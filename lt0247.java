import java.util.*;

class Solution {
    public List<String> findStrobogrammatic(int n) {
        
        map.put('0', '0');
        map.put('1', '1');
        map.put('6', '9');
        map.put('8', '8');
        map.put('9', '6');
        List<String> res = new ArrayList<>();
        helper(0, n, new char[n], res);
        return res;
    }
    
    public void helper(int step, int n, char[] temp, List<String> res){
        if(step > n - step - 1){
            res.add(String.valueOf(temp));
            return;
        }
        char[] can = step == n - step - 1 ? can1 : can2;
        for(int i = 0; i < can.length; i++){
            if(step == 0 && i == 0 && step != n - step - 1)
                continue;
            temp[step] = can[i];
            temp[n - step - 1] = map.get(can[i]); 
            helper(step + 1, n, temp, res);
        }
    }
    
    private final char[] can1 = new char[]{'0', '1', '8'};
    private final char[] can2 = new char[]{'0', '1', '6', '8', '9'};
    private final Map<Character, Character> map = new HashMap<>();
}