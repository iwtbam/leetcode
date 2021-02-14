// https://leetcode-cn.com/problems/remove-covered-intervals/
// remove covered intervals
class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int size = intervals.length;
        
        if(size <= 1)
            return size;
        
        Arrays.sort(intervals, (e1, e2) -> { return e1[0] - e2[0] == 0 ? e1[1] - e2[1] : e1[0] - e2[0];});
        
        Stack<int[]> q = new Stack<>();
        
        q.push(intervals[0]);
        
        for(int i = 1; i < size; i++){
            int[] cur = intervals[i];
            boolean flag = false;
            while(q.size() > 0){
                int[] top = q.peek();
                if(top[0] >= cur[0] && top[1] <= cur[1]){
                    q.pop();
                }else{
                    if(top[0] <= cur[0] && top[1] >= cur[1]){
                        flag = true;
                    }
                    
                    break;
                }
                
            }
            
            if(!flag)
                q.push(cur);
        }
        
        return q.size();
    }
}