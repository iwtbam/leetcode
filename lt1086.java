// https://leetcode-cn.com/problems/high-five/
// high five
class Solution {
    public int[][] highFive(int[][] items) {
        
        int len = items.length;
        
        Arrays.sort(items, (arr1, arr2) -> {
            return arr1[0] - arr2[0] == 0 ? arr2[1] - arr1[1] : arr1[0] - arr2[0];    
        });
        
        Map<Integer, Integer> ids = new HashMap();
        
        for(int i = 0; i < len; i++){
            if(!ids.containsKey(items[i][0]))
                ids.put(items[i][0], i);
        }
        
        int size = ids.size(), pos = 0;
        int[][] res = new int[size][];
        
        for(int index : ids.values()){
            int avg = 0;
            for(int i = 0; i < 5; i++)
                avg += items[index + i][1];
            avg /= 5;
            res[pos++] = new int[]{items[index][0], avg};
        }
            
        return res;
                    
    }
}