// https://leetcode-cn.com/problems/insert-interval/
// insert interval
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();
        int size = intervals.length;

        int newStart = newInterval[0];
        int i = 0;
        while(i < size && newStart > intervals[i][0]){
            res.add(intervals[i++]);
        }
        
        if(res.size() == 0){
            res.add(newInterval);
        }else{
            int[] interval = res.get(res.size() - 1);
            if(newInterval[0] <= interval[1])            
                interval[1] = Math.max(interval[1], newInterval[1]);
            else
                res.add(newInterval);
        }

        while(i < size){
            int[] interval = res.get(res.size() - 1);
            if(interval[1] < intervals[i][0]){
                res.add(intervals[i]);
            }else{
                interval[1] = Math.max(interval[1], intervals[i][1]);
            }
            i++;
        }

        return res.toArray(new int[res.size()][]);
    }

    private final static int BOUND = Integer.MIN_VALUE;
}