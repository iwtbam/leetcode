class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int len = s.length();
        if(len == 0)
            return 0;
        int[] costs = new int[len];
        
        for(int i = 0; i < len; i++)
            costs[i] = Math.abs(s.charAt(i) - t.charAt(i));
  
        
        int maxLen = 0;
        
        int left = 0, right = 0, cur = 0;
        while(left <= right && right < len){
            cur += costs[right];
            if(cur <= maxCost)
                maxLen = Math.max(maxLen, right - left + 1);
            
            while(cur > maxCost){
                cur -= costs[left++];
            }
            
            right++;
        }
        
        return maxLen;
        
    }
}