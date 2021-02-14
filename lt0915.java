// https://leetcode-cn.com/problems/partition-array-into-disjoint-intervals/
// partition array into disjoint intervals
class Solution {
    public int partitionDisjoint(int[] A) {
        int len = A.length;
        int[] left  = new int[len];
        int[] right = new int[len];
        
        left[0] = A[0];
        right[len - 1] = A[len - 1];
        
        for(int i = 1; i < len; i++){
            left[i] = Math.max(left[i - 1], A[i]);
            right[len - i - 1] = Math.min(right[len - i], A[len - i - 1]);
        }
        
//         for(int i = 0; i < len; i++)
//             System.out.print(right[i] + " ");
//         System.out.println();
        
//         for(int i = 0; i < len; i++)
//             System.out.print(left[i] + " ");
//         System.out.println();
        
        for(int i = 1; i < len; i++){
            if(right[i] >= left[i - 1])
                return i;
        }
       
        return 0;
    }
}