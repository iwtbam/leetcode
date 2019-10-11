import java.util.*;

class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> times = new ArrayList<>();
        for(String timePoint : timePoints){
            String[] strs = timePoint.split(":");
            Integer temp = Integer.parseInt(strs[0]) * 60 + Integer.parseInt(strs[1]); 
            times.add(temp);
            times.add(temp + 1440);
        }
        
        Collections.sort(times);
        
        int minDiff = Integer.MAX_VALUE;
        
        for(int i = 0; i < times.size() - 1; i++){
            minDiff = Math.min(minDiff, times.get(i + 1) - times.get(i));
        }
        
        return minDiff;
        
        
    }
}