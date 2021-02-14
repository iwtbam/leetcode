// https://leetcode-cn.com/problems/number-of-ships-in-a-rectangle/
// number of ships in a rectangle
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *     public boolean hasShips(int[] topRight, int[] bottomLeft);
 * }
 */

class Solution {
    public int countShips(Sea sea, int[] topRight, int[] bottomLeft) {
        int bx = bottomLeft[0], tx = topRight[0], by = bottomLeft[1], ty = topRight[1];
        ArrayList<Integer> xs = new ArrayList<>();
        searchX(sea, bx, tx, by, ty, xs);
        int count = 0;
        for(int x : xs)
            count += searchY(sea, x, by, ty);
      
        return count;
    }
    
    public void searchX(Sea sea, int sx, int ex, int sy, int ey, List<Integer> xs){
        
        if(ex == sx){
            xs.add(ex);
            return;
        }
        
        int mid = (sx + ex) / 2;
   
        if(sea.hasShips(new int[]{mid, ey}, new int[]{sx, sy})){
            searchX(sea, sx, mid, sy, ey, xs);
        }
        
        if(sea.hasShips(new int[]{ex, ey}, new int[]{mid + 1, sy})){
            searchX(sea, mid + 1, ex, sy, ey, xs);
        }
    }
    
    public int searchY(Sea sea, int x, int sy, int ey){
        if(sy == ey)
            return 1;
        
        int count = 0;
        int mid = (sy + ey) / 2;
        
        if(sea.hasShips(new int[]{x, mid}, new int[]{x, sy})){
            count += searchY(sea, x, sy, mid);
        }
        
        if(sea.hasShips(new int[]{x, ey}, new int[]{x, mid + 1})){
            count += searchY(sea, x, mid + 1, ey);
        }
        
        return count;
    }
}