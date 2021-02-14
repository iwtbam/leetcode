import java.util.*;

class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        long l = lower, h = 0; 
        StringBuffer sb = new StringBuffer();
        List<String> res = new ArrayList<>();
        for(int i = 0; i < nums.length; i++){
            h = nums[i];
            if(h - l >= 1){
                sb.append(l);
                if(h - l > 1){
                    sb.append("->");
                    sb.append(h - 1);
                }
                res.add(sb.toString());
                sb.delete(0, sb.length()); 
            }
            l = h + 1;
        }
        
        if(upper - l >= 0){
            sb.append(l);
            if(upper - l > 0){
                sb.append("->");
                sb.append(upper);
            }
            res.add(sb.toString());
        }
        
        return res;
    }
}