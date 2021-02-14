// https://leetcode-cn.com/problems/minimum-time-visiting-all-points/
// minimum time visiting all points
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int step = 0;
        int N = points.length;
        if(N == 0)
            return step;
        int[] pre = points[0];
        for(int i = 1; i < N; i++){
            int dx = Math.abs(points[i][0] - pre[0]);
            int dy = Math.abs(points[i][1] - pre[1]);
            step += Math.max(dx, dy);    
            pre = points[i];
        }
        
        return step;
    }
}