// https://leetcode-cn.com/problems/remove-interval/
// remove interval
class Solution {
    public List<List<Integer>> removeInterval(int[][] intervals, int[] toBeRemoved) {
        List<List<Integer>> res = new ArrayList<>();
        for(int[] interval : intervals){
            List<Integer> item = null;
            
            if(interval[1] <= toBeRemoved[0] || interval[0] >= toBeRemoved[1]){
                item = new ArrayList<>();
                item.add(interval[0]);
                item.add(interval[1]);
                res.add(item);
                continue;
            }
      
            
            
            int left = Math.max(interval[0], toBeRemoved[0]);
            int right = Math.min(interval[1], toBeRemoved[1]);
            if(left > interval[0]){
                item = new ArrayList<>();
                item.add(interval[0]);
                item.add(left);
                res.add(item);
            }
            
            if(right < interval[1]){
                item = new ArrayList<>();
                item.add(right);
                item.add(interval[1]);
                res.add(item);
            }
        }
        
        return res;
    }
}