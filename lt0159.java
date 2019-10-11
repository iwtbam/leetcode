import java.util.*;

class Solution {
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        int right = 0, left = 0, len = s.length(), maxLen = 0;
        Map<Character, Integer> record = new HashMap<>();
        while(right < len){
            char c = s.charAt(right);
            record.put(c, record.getOrDefault(c, 0) + 1);
            if(record.size() <= 2)
                maxLen = Math.max(maxLen, right - left + 1);

            while(record.size() > 2 && left <= right){
                char lc = s.charAt(left);
                Integer count = record.get(lc);
                
                if(count <= 1)
                    record.remove(lc);
                else
                    record.put(lc, count - 1);
                left++;

            }    
            right++;
        }  
        return maxLen;
    }
}