import java.util.*;

class Solution {
    public int minCostToMoveChips(int[] chips) {
        Map<Integer, Integer> count = new HashMap<>();
        int len = chips.length;
        for(int chip : chips){
            count.put(chip, count.getOrDefault(chip, 0) + 1);
        }
        
        ArrayList<Integer> indexs = new ArrayList<>();
        for(int key : count.keySet())
            indexs.add(key);
        
        int minCost = Integer.MAX_VALUE;
        int keyLen = indexs.size();
        for(int i = 0;  i < keyLen; i++){
            int cost = 0;
            for(int j = 0; j < keyLen; j++){
                if(i == j)
                    continue;
                cost += (Math.abs(indexs.get(j) - indexs.get(i))) % 2 * count.get(indexs.get(j));
            }
            minCost = Math.min(cost, minCost);
        }
        
        return minCost;
    }
}