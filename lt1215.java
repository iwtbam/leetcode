import java.util.*;
class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        for(int i = 0; i < 10; i++)
            helper(low, high, i, 0);
        
        List<Integer> res = new ArrayList<>();
        
        for(int num : set)
            res.add(num);
        
        Collections.sort(res);
        return res;
    }
    
    public void helper(int low, int high, int cur, long sum){
        if(sum > high)
            return;
        if(sum >= low)
            set.add((int)sum);
        
        if(cur - 1 >= 0)
            helper(low, high, cur - 1, sum * 10 + cur);
        
        if(cur + 1 < 10)
            helper(low, high, cur + 1, sum * 10 + cur);
    }
    
    private Set<Integer> set = new HashSet<>();
}