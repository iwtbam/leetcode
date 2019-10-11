import java.util.*;

class Solution {
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
    
        this.N = N;
        count = new int[N];
        ans = new int[N];
        
        Arrays.fill(count, 1);
        
        for(int i = 0; i < N; i++)
            graph.add(new HashSet<Integer>());
        
        for(int[] edge: edges){
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1);
        
        return ans;
    }
    
    
    public void dfs(int node, int parent){
        Set<Integer> children = graph.get(node);
        for(Integer child:children){
         
            if(child == parent)
                continue;
            dfs(child, node);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }
    
    public void dfs2(int node, int parent){
        Set<Integer> children = graph.get(node);
        for(Integer child : children){
            if(child == parent)
                continue;
            ans[child] = ans[node] - count[child] + N - count[child];
            dfs2(child, node);
        }
    }
    
    private int N = 0;
    private int[] count = null;
    private int[] ans = null;
    private List<Set<Integer>> graph = new ArrayList<>();
}