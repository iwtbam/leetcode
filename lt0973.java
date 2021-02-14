// https://leetcode-cn.com/problems/k-closest-points-to-origin/
// k closest points to origin
class Solution {
    public int[][] kClosest(int[][] points, int K) {
        if(K == 0 || points.length == 0)
            return null;
        
        
        Arrays.sort(points, new Comparator<int[]>(){
           public int compare(int[] p1, int[] p2){
                int d1 = p1[0] * p1[0] + p1[1] * p1[1];
                int d2 = p2[0] * p2[0] + p2[1] * p2[1];
                return d1 - d2;
            } 
        });
        
        int[][] res = new int[K][2];
        
        for(int i = 0; i < K; i++)
            res[i] = points[i];
        
        return res;
    }
}