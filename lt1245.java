import java.util.*;

class Solution {
    public int treeDiameter(int[][] edges) {
        
        if(edges.length == 0)
            return 0;
        
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int[] edge : edges){
            graph.computeIfAbsent(edge[0], z -> new ArrayList<>()).add(edge[1]);
            graph.computeIfAbsent(edge[1], z -> new ArrayList<>()).add(edge[0]);
        }
        
        List<Integer> vertices = new ArrayList<>();
        Set<Integer> record = new HashSet<>();
        record.add(edges[0][0]);
        dfs(graph, record,  edges[0][0]);
        return ans;
    }
    
    public int dfs(Map<Integer, List<Integer>> graph, Set<Integer> vis, int vert){
        List<Integer> nexts = graph.get(vert);
        
        int[] res = new int[]{0, 0};
        
        List<Integer> dis = new ArrayList<>();
        
        for(int next : nexts){
            if(vis.contains(next))
                continue;
            vis.add(next);
            dis.add(dfs(graph, vis, next) + 1);
        }
     
        res = helper(dis);
        ans = Math.max(ans, res[0]);
 
        
        return res[1];
    }
    
    public int[] helper(List<Integer> arrs){
        int max1 = 0;
        int max2 = 0;
        
        for(int ele : arrs){
            if(ele > max1){
                max2 = max1;
                max1 = ele;
                continue;
            }
            
            if(ele > max2){
                max2 = ele;
            }
                
        }
        
        return new int[]{max1 + max2, max1};
    }
    
    private int ans = 0;
}