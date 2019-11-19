import java.util.*;

class Solution {
    int[] dxs = new int[]{ 1, 1, 2, 2, -1, -1, -2, -2};
    int[] dys = new int[]{-2, 2, 1,-1,  2, -2, -1,  1};
    
    public int minKnightMoves(int x, int y) {
        if(x == 0 && y==0)
            return 0;
        
        Queue<int[]> q = new LinkedList<>();
        Queue<Integer> steps = new LinkedList<>();
        Set<Integer> vis = new HashSet<>();
        q.offer(new int[]{0, 0});
        steps.offer(0);
        vis.add(301 * 10000 + 301);
        while(true){
            int[] top = q.poll();
            int step = steps.poll() + 1;
            for(int i = 0; i < 8; i++){
                int nx = top[0] + dxs[i];
                int ny = top[1] + dys[i];
                int num = (nx + 301) * 10000 + ny + 301;
                if(nx == x && ny == y)
                    return step;
                if(vis.contains(num))
                    continue;
                vis.add(num);
                steps.add(step);
                q.offer(new int[]{nx, ny});
            }
        }
    }
}