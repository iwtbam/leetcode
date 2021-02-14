// https://leetcode-cn.com/problems/redundant-connection-ii/
// redundant connection ii
class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int len = edges.length;
        int[] first = null, second = null;
        int[] roots = new int[len + 1];
        for(int i = 0; i < len; i++){
            int[] edge = edges[i];
            if(roots[edge[1]] == 0){
                roots[edge[1]] = edge[0];
            }else{
                first = new int[]{roots[edge[1]], edge[1]};
                second = new int[]{edge[0], edge[1]};
                edge[1] = 0;
            }
            
        }
        
        for(int i = 0; i <= len; i++)
            roots[i] = i;
        
        for(int i = 0; i < len; i++){
            int[] edge = edges[i];
            if(edge[1] == 0)
                continue;
            int x = find(roots, edge[0]);
            int y = find(roots, edge[1]);
            
            if(x == y)
                return first == null ? edge: first;
            roots[x] = y;
        }
        
        return second;
    
    }
    
    int find(int[] root, int i){
        return root[i] == i ? i : find(root, root[i]);
    }
}