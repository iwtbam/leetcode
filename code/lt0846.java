import java.util.*;

class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        int L = hand.length;
        if(L % W != 0)
            return false;
        
        Map<Integer, Integer> record = new TreeMap<>();
        for(int i = 0; i < L; i++){
            record.put(hand[i], record.getOrDefault(hand[i], 0) + 1);
        }
        
        for(Map.Entry<Integer, Integer> entry : record.entrySet()){
            int count = entry.getValue();
            if(count == 0)
                continue;
            int start = entry.getKey();
            
            for(int i = start; i < start + W; i++){
                if(!record.containsKey(i))
                    return false;
                if(record.get(i) < count)
                    return false;
                record.put(i, record.get(i) - count);
            }
        }
        
        return true;
    }
}