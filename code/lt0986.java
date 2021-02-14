// https://leetcode-cn.com/problems/interval-list-intersections/
// interval list intersections
class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        int aL = A.length;
        int bL = B.length;
        int i = 0, j = 0;
        
        List<int[]> resList = new ArrayList<>();
        
        while(i < aL && j < bL){
            int[] a = A[i];
            int[] b = B[j];
           

            if(a[0] > b[1]){
                j++;
                continue;
            }
            
            if(b[0] > a[1]){
                i++;
                continue;
            }
            
            // System.out.println(i + " " + j);
            
            resList.add(new int[]{Math.max(a[0], b[0]), Math.min(a[1], b[1])});
            
            if(b[1] >= a[1])
                i++;
            
            if(a[1] >= b[1])
                j++;
            
        }
        
        int size = resList.size();
        // int[][] res = null;
        int[][] res = new int[size][2];
        for(i = 0; i < size; i++){
            res[i] = resList.get(i);
        }
        return res;
    }
}