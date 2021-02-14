import java.util.*;

class Solution {
    
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        
        if(n == 1)
            return 0;
        
        final int OVER = (1 << n) - 1;
        int[][] visited = new int[n][1 << n];
        
        Queue<int[]> q = new LinkedList<>();
        
        for(int i = 0; i < n; i++){
            visited[i][1 << i] = 1;
            q.offer(new int[]{i, 1 << i});
        }
        
        int step = 0;
        
        while(q.size() > 0){
            step++;
            
            int size = q.size();
            
            for(int i = 0; i < size; i++){
            
                int[] top = q.poll();
                int node  = top[0];
                int state = top[1];

                for(int next : graph[node]){
                    int ns = state | 1 << next;    
                    if(ns == OVER)
                        return step ;

                    if(visited[next][ns] == 1)
                        continue;
                    visited[next][ns] = 1;
                    q.offer(new int[]{next, ns});
                }
            }
        }
        
        return -1;
    }
}