import java.util.*;

class Solution {
    
    int[] dxs = new int[]{0,  0, 1, -1, 1,  1, -1, -1};
    int[] dys = new int[]{1, -1, 0,  0, 1, -1, -1,  1};
    
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        int[][] vis = new int[8][8];
        for(int[] queen : queens){
            vis[queen[0]][queen[1]] = 1;
        }
        
        int count = 0;
        
        List<List<Integer>> res =  new ArrayList<>();
        
        for(int i = 0; i < 8; i++){
            int cx = king[0] + dxs[i], cy = king[1] + dys[i];
            List<Integer> li = new ArrayList<>();
            while(cx >= 0 && cy >= 0 && cx < 8 && cy < 8){
                if(vis[cx][cy] == 1){
                    li.add(cx);
                    li.add(cy);
                    res.add(li);
                    count++;
                    break;
                }
                
                cx += dxs[i];
                cy += dys[i];
            }
        }
        
        return res;
        
    }
}