import java.util.*;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> record = new HashMap<>();
        for(int i = 0; i < arr.length; i++)
            record.put(arr[i], record.getOrDefault(arr[i], 0) + 1);
        Set<Integer> visited = new HashSet<Integer>();
        for(Integer val : record.values()){
            if(visited.contains(val))
                return false;
            visited.add(val);
        }
        
        return true;
    }
}