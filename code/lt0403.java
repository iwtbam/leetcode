import java.util.*;

// 回溯+记忆化
// class Solution {
//     public boolean canCross(int[] stones) {
//         int len = stones.length;
//         memos = new int[len][len + 1];
//         for(int i = 0; i < len; i++)
//             Arrays.fill(memos[i], -1);
//         return canCross(stones, 0, 1);
//     }
    
    
//     public boolean canCross(int[] stones, int cur, int k){
        
//         if(cur == stones.length - 1)
//             return true;
//         if(memos[cur][k]!=-1)
//             return memos[cur][k] == 1;
        
//         int nextPos = stones[cur] + k;
//         int next = cur + 1;
        
//         while(next < stones.length && stones[next] < nextPos)
//             next++;
        
//         if(next == stones.length)
//             return false;
            
//         if(stones[next]!= nextPos)
//             return false;
        
//         memos[cur][k] = canCross(stones, next, k) || canCross(stones, next, k - 1) || canCross(stones, next, k + 1) ? 1 : 0;
        
//         return memos[cur][k] == 1;
        
//     }
    
//     private int[][] memos = null;
// }

// 回溯超时
// class Solution {
//     public boolean canCross(int[] stones) {
//        return canCross(stones, 0, 1);
//     }
    
    
//     public boolean canCross(int[] stones, int cur, int k){
//         
//         if(cur == stones.length - 1)
//             return true;
        
//         int nextPos = stones[cur] + k;
//         int next = cur + 1;
        
//         while(next < stones.length && stones[next] < nextPos)
//             next++;
        
//         if(next == stones.length)
//             return false;
            
//         if(stones[next]!= nextPos)
//             return false;      
//         return canCross(stones, next, k) || canCross(stones, next, k - 1) || canCross(stones, next, k + 1);
//     }
// }